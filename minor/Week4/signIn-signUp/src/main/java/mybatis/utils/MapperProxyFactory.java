package mybatis.utils;

import connectionpool.ConnectionPool;
import mybatis.anno.ParamFaken;
import mybatis.anno.SelectFaken;
import mybatis.iface.TypeHandler;

import java.lang.annotation.Annotation;
import java.lang.reflect.*;
import java.sql.*;
import java.util.*;

//制造mapper代理对象
public class MapperProxyFactory {

    private static final Map<Class, TypeHandler> typeHandlerMap = new HashMap<>();
    private static final ConnectionPool connectionPool;

    static {
        try {
            connectionPool = new ConnectionPool();
        } catch (SQLException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
        //注册TypeHandler
        typeHandlerMap.put(Integer.class, new IntegerTypeHandler());
        typeHandlerMap.put(String.class, new StringTypeHandler());
    }

    public static <T> T getMapper(Class<T> mapper) {
        Object proxyInstance = Proxy.newProxyInstance(
                mapper.getClassLoader(),
                new Class[]{mapper},
                (proxy, method, args) -> {
                    //sql处理,返回结果
                    //1. 获取连接
                    Connection connection = connectionPool.getConnection();

                    //2. 获取注解值->sql
                    List<Object> list = new ArrayList<>();
                    if (method.isAnnotationPresent(SelectFaken.class)) {
                        SelectFaken anno = method.getAnnotation(SelectFaken.class);
                        String sql = anno.value();

                        //3. 传入参数名对应参数值-> paramMappingMap内 存放
                        // "name" = xxx, "id" = xx(参数名和值)
                        Map<String, Object> paramMappingMap = new HashMap<>();
                        Parameter[] parameters = method.getParameters();
                        for (int i = 0; i < parameters.length; i++) {
                            paramMappingMap.put(parameters[i].getAnnotation(ParamFaken.class).value(), args[i]);
                        }

                        //4. 解析sql语句, #{xx}->?, 并解析占位符内的xx放在handler的一个List中
                        ParameterMappingTokenHandler handler = new ParameterMappingTokenHandler();
                        //解析器,解析sql
                        GenericTokenParser parser = new GenericTokenParser("#{", "}", handler);
                        //向解析器传入了一个handler, 它会将解析出来的字段内的内容进行处理, 外部已经定义了一个类ParameterMappingTokenHandler来处理
                        //handler接受占位符内容, 放在这个类的一个存放ParameterMapping对象的容器中, 即解析器解析sql, 按顺序提取占位符内容
                        //存放到一个容器中.
                        List<ParameterMapping> parameterMappings = handler.getParameterMappings();
                        sql = parser.parse(sql);

                        //5. 构造preparedStatement并且赋值
                        PreparedStatement statement = connection.prepareStatement(sql);
                        for (int i = 0; i < parameterMappings.size(); i++) {
                            String property = parameterMappings.get(i).getProperty();//取sql语句第i+1个参数名字
                            Object value = paramMappingMap.get(property);//根据参数名字回到map找值
                            Class<?> classType = value.getClass();//取值的类型
                            typeHandlerMap.get(classType).setParam(statement, i + 1, value);//根据类型找到TypeHandler给statement设置具体参数值
                        }

                        //6. 执行sql, 获取结果集
                        statement.execute();
                        ResultSet resultSet = statement.getResultSet();

                        //7. 获取方法的返回类型
                        //拿到pojo类型, 如果是单条记录查询直接赋值, 如果多条记录查询, 则会取到List<?>的?赋值
                        Class resultType = null;
                        Type genericReturnType = method.getGenericReturnType();
                        if (genericReturnType instanceof Class) {
                            resultType = (Class) genericReturnType;
                        } else if (genericReturnType instanceof ParameterizedType) {
                            Type[] actualTypeArguments = ((ParameterizedType) genericReturnType).getActualTypeArguments();
                            resultType = (Class) actualTypeArguments[0];
                        }

                        //8. 处理结果集
                        ResultSetMetaData metaData = resultSet.getMetaData();//原始数据
                        List<String> columnList = new ArrayList<>();//查询到的字段
                        for (int i = 0; i < metaData.getColumnCount(); i++) {
                            columnList.add(metaData.getColumnName(i + 1));
                        }

                        //获取pojo类的属性名和set方法
                        HashMap<String, Method> setterMethodMap = new HashMap<>();
                        for (Method declaredMethod : resultType.getDeclaredMethods()) {
                            if (declaredMethod.getName().startsWith("set")) {
                                String propertyName = declaredMethod.getName().substring(3);
                                propertyName = propertyName.substring(0, 1).toLowerCase(Locale.ROOT) + propertyName.substring(1);
                                setterMethodMap.put(propertyName, declaredMethod);
                            }
                        }

                        while (resultSet.next()) {
                            Object instance = resultType.newInstance();//创建实例对象
                            for (int i = 0; i < columnList.size(); i++) {
                                //对实例对象的成员变量赋值
                                //1. 拿到当前字段对应的实例类的setter方法
                                String column = columnList.get(i);
                                Method setter = setterMethodMap.get(column);

                                //2. 获取setter方法的参数类型
                                Class<?> parameterType = setter.getParameterTypes()[0];

                                //3. 获取相应的typehandler
                                TypeHandler typeHandler = typeHandlerMap.get(parameterType);

                                //4. 调用setter方法, 赋值
                                setter.invoke(instance, typeHandler.getResult(resultSet, column));
                            }
                            list.add(instance);
                        }

                        connectionPool.releaseConnection(connection);
                        //9. 根据方法返回类型返回
                        if (method.getReturnType().equals(List.class)) {
                            return list;
                        }else if (method.getReturnType().equals(void.class)) {
                            return null;
                        } else {
                            if (!list.isEmpty()) {
                                return list.get(0);
                            }else return null;
                        }
                    }
                    else {
                        //增删改只需要执行语句不需要返回值, 重点在获取注解值
                        try {
                            // 获取方法上的所有注解 (最多就一个hhh)
                            Annotation[] annotations = method.getAnnotations();
                            // 获取注解的类型
                            Class<? extends Annotation> annotationType = annotations[0].annotationType();
                            // 获取注解的值
                            // 通过反射获取 value 方法
                            Method valueMethod = annotationType.getDeclaredMethod("value");
                            // 如果注解有 value 方法，就获取值

                            //一样的执行语句逻辑
                            String sql = (String) valueMethod.invoke(annotations[0]);

                            //3. 传入参数名对应参数值-> paramMappingMap内 存放
                            // "name" = xxx, "id" = xx(参数名和值)
                            Map<String, Object> paramMappingMap = new HashMap<>();
                            Parameter[] parameters = method.getParameters();
                            for (int i = 0; i < parameters.length; i++) {
                                paramMappingMap.put(parameters[i].getAnnotation(ParamFaken.class).value(), args[i]);
                            }

                            //4. 解析sql语句, #{xx}->?, 并解析占位符内的xx放在handler的一个List中
                            ParameterMappingTokenHandler handler = new ParameterMappingTokenHandler();
                            //解析器,解析sql
                            GenericTokenParser parser = new GenericTokenParser("#{", "}", handler);
                            //向解析器传入了一个handler, 它会将解析出来的字段内的内容进行处理, 外部已经定义了一个类ParameterMappingTokenHandler来处理
                            //handler接受占位符内容, 放在这个类的一个存放ParameterMapping对象的容器中, 即解析器解析sql, 按顺序提取占位符内容
                            //存放到一个容器中.
                            List<ParameterMapping> parameterMappings = handler.getParameterMappings();
                            sql = parser.parse(sql);

                            //5. 构造preparedStatement并且赋值
                            PreparedStatement statement = connection.prepareStatement(sql);
                            for (int i = 0; i < parameterMappings.size(); i++) {
                                String property = parameterMappings.get(i).getProperty();//取sql语句第i+1个参数名字
                                Object value = paramMappingMap.get(property);//根据参数名字回到map找值
                                Class<?> classType = value.getClass();//取值的类型
                                typeHandlerMap.get(classType).setParam(statement, i + 1, value);//根据类型找到TypeHandler给statement设置具体参数值
                            }

                            //6. 执行sql, 获取受影响的行数
                            connectionPool.releaseConnection(connection);
                            return statement.executeUpdate();
                        } catch (NoSuchMethodException e) {
                            throw new RuntimeException(e);
                        }
                    }
                });
        return (T) proxyInstance;
    }
}















