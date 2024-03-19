import utils.JDBCUtils;

import utils.MyHandler;
import pojo.User;

import java.sql.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Test {
    public static void main(String[] args) throws Exception {
        //创建连接
        System.out.println("正在获取与数据库的连接");
        try {
            Connection connection = JDBCUtils.getConnection();
            System.out.println("连接成功 链接对象:" + connection);
            Statement statement = JDBCUtils.getStatement();
            System.out.println("执行对象:" + statement);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

//        User user = new User("31230047861", "hs", 123, LocalDate.now());
//        User user1 = new User("31230047862", "hs1", 123, LocalDate.now());
//        JDBCUtils.insert(user);
//        JDBCUtils.insert(user1);

        try {
            List<User> query = JDBCUtils.query("username = 'hs'", new MyHandler<User>() {
                @Override
                public List<User> handleResultSet(ResultSet resultSet) throws SQLException {
                    List<User> users = new ArrayList<>();
                    resultSet.next();
                    users.add(new User(
                            resultSet.getString("user_id"),
                            resultSet.getString("username"),
                            resultSet.getInt("user_score"),
                            resultSet.getDate("create_time")
                    ));
                    return users;
                }
            });
            System.out.println(query);
            List<User> query1 = JDBCUtils.query("user_score=123", new MyHandler<User>() {
                @Override
                public List<User> handleResultSet(ResultSet resultSet) throws SQLException {
                    List<User> users = new ArrayList<>();
                    while (resultSet.next()) {
                        users.add(new User(
                                resultSet.getString("user_id"),
                                resultSet.getString("username"),
                                resultSet.getInt("user_score"),
                                resultSet.getDate("create_time")
                        ));
                    }
                    return users;
                }
            });
            System.out.println(query1);

            JDBCUtils.update("id = 4", "12345678911", "xdj", 321, new Date(System.currentTimeMillis()));
            JDBCUtils.delete("id = 5");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}