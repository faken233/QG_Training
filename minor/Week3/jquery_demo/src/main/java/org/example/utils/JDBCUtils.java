package org.example.utils;

import org.example.pojo.User;

import java.io.FileReader;
import java.net.URL;
import java.sql.*;
import java.util.Properties;

public class JDBCUtils {
    private static final String driver;
    private static final String url;
    private static final String username;
    private static final String password;
    private static final Connection connection;
    private static final Statement statement;


    static {
        //创建properties对象
        Properties properties = new Properties();
        try {
            //加载文件
            ClassLoader classLoader = JDBCUtils.class.getClassLoader();
            URL resource = classLoader.getResource("properties.properties");
            properties.load(new FileReader(resource.getFile()));
            //获取键值对,进行赋值
            driver = properties.getProperty("driver");
            url = properties.getProperty("url");
            username = properties.getProperty("username");
            password = properties.getProperty("password");
            //加载驱动
            Class.forName(driver);
            //创建与数据库的连接
            connection = DriverManager.getConnection(url, username, password);
            //创建命令对象
            statement = connection.createStatement();
        } catch (Exception e) {
            System.out.println("加载出错!");
            throw new RuntimeException(e);
        }
    }

    public static Connection getConnection() {
        //获取与数据库的连接
        return connection;
    }

    public static Statement getStatement() {
        return statement;
    }

    public static <T> T query(String condition, MyHandler<T> myHandler) throws Exception {

        //编写sql语句, 拼接condition条件
        String sql = "select * from test3.employee" + " where " + condition;
        //执行语句,返回ResultSet
        ResultSet resultSet = statement.executeQuery(sql);
        //手写匿名内部类处理结果集
        T ts = myHandler.handleResultSet(resultSet);
        //关闭
        resultSet.close();
        return ts;

    }

    public static boolean insert(User user) throws SQLException {
        //获取实体类对象属性
        int userId = user.getId();
        String username = user.getName();
        int userAge = user.getAge();
        String dept = user.getDept();
        Timestamp createTime = user.getCreateTime();
        //准备sql语句
        PreparedStatement preparedStatement = connection.prepareStatement("insert into test3.employee "
                + " (id, name,age, dept, create_time) " +
                " values (?,?,?,?,?)");
        //拼接
        preparedStatement.setInt(1, userId);
        preparedStatement.setString(2, username);
        preparedStatement.setInt(3, userAge);
        preparedStatement.setString(4, dept);
        preparedStatement.setTimestamp(5, createTime);
        //执行
        return preparedStatement.execute();
    }

    public static int update(String condition, String userId, String username, int userScore, Date createTime) throws SQLException {
        String sql = "update test3.employee set id = ?, name = ?, age = ?, dept = ? , create_time = ?  where " + condition;
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, userId);
        preparedStatement.setString(2, username);
        preparedStatement.setInt(3, userScore);
        preparedStatement.setDate(4, createTime);

        return preparedStatement.executeUpdate();
    }

    public static boolean delete(String condition) throws SQLException {
        String sql = "delete from test3.employee where " + condition;
        return statement.execute(sql);

    }

    public static void closeResource(Connection connection, Statement statement) throws SQLException {
        connection.close();
        statement.close();
    }
}

















