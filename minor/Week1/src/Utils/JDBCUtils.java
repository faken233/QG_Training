package utils;

import pojo.User;

import java.io.FileReader;
import java.sql.*;
import java.util.List;
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
            properties.load(new FileReader("src/properties.properties"));
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

    public static <T> List<T> query(String condition, MyHandler<T> myHandler) throws Exception {
        String sql = "select * from test2.user_table" + " where " + condition;

        ResultSet resultSet = statement.executeQuery(sql);

        return myHandler.handleResultSet(resultSet);
    }

    public static boolean insert(User user) throws SQLException {
        String userId = user.getUserId();
        String username = user.getUsername();
        int userScore = user.getUserScore();
        Date createTime = user.getCreateTime();
        PreparedStatement preparedStatement = connection.prepareStatement("insert into test2.user_table " + " (user_id, username, user_score, create_time) " +
                " values (?,?,?,?)");
        preparedStatement.setString(1, userId);
        preparedStatement.setString(2, username);
        preparedStatement.setString(3, userScore + "");
        preparedStatement.setDate(4, createTime);
        return preparedStatement.execute();
    }

    public static int update(String condition, String userId, String username, int userScore, Date createTime) throws SQLException {
        String sql = "update test2.user_table set user_id = ?, username = ?, user_score = ?, create_time = ? where " + condition;
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, userId);
        preparedStatement.setString(2, username);
        preparedStatement.setInt(3, userScore);
        preparedStatement.setDate(4, createTime);

        return preparedStatement.executeUpdate();
    }

    public static boolean delete(String condition) throws SQLException {
        String sql = "delete from test2.user_table where " + condition;
        return statement.execute(sql);

    }
}

















