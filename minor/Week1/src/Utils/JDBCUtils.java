package Utils;

import pojo.User;

import java.io.FileReader;
import java.sql.*;
import java.time.LocalDate;
import java.util.Properties;
import java.util.Set;
import java.util.StringJoiner;

public class JDBCUtils {
    private static final String driver;
    private static final String url;
    private static final String username;
    private static final String password;
    private static final String table;

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
            table = properties.getProperty("table");
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
        String sql = "select * from " + table + " where " + condition;

        ResultSet resultSet = statement.executeQuery(sql);
        return myHandler.handleResultSet(resultSet);
    }

    public static boolean insert(User user) throws SQLException {
        String userId = user.getUserId();
        String username = user.getUsername();
        int userScore = user.getUserScore();
        LocalDate createTime = user.getCreateTime();
        PreparedStatement preparedStatement = connection.prepareStatement("insert into " + table + " (user_id, username, user_score, create_time) " +
                " values (?,?,?,?)");
        preparedStatement.setString(1, userId);
        preparedStatement.setString(2, username);
        preparedStatement.setString(3, userScore + "");
        preparedStatement.setDate(4, Date.valueOf(createTime));
        return preparedStatement.execute();
    }
}

















