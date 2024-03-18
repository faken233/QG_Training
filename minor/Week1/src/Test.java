import Utils.JDBCUtils;

import Utils.MyHandler;
import pojo.User;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDate;
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

        User user = new User("31230047861", "hs", 123, LocalDate.now());
        User user1 = new User("31230047862", "hs1", 123, LocalDate.now());
        JDBCUtils.insert(user);
        JDBCUtils.insert(user1);

        try {
            User query = JDBCUtils.query("username = 'hs'", new MyHandler<User>() {
                @Override
                public User handleResultSet(ResultSet resultSet) throws SQLException {
                    resultSet.next();
                    User k_user = new User(
                            resultSet.getString("user_id"),
                            resultSet.getString("username"),
                            resultSet.getInt("user_score"),
                            resultSet.getDate("create_time").toLocalDate()
                    );
                    return user1;
                }
            });
            System.out.println(query);
            Set<User> query1 = JDBCUtils.query("user_score=123", new MyHandler<Set<User>>() {
                @Override
                public Set<User> handleResultSet(ResultSet resultSet) throws SQLException {
                    Set<User> users = new HashSet<>();
                    while (resultSet.next()) {
                        users.add(new User(
                                resultSet.getString("user_id"),
                                resultSet.getString("username"),
                                resultSet.getInt("user_score"),
                                resultSet.getDate("create_time").toLocalDate()
                        ));
                    }
                    return users;
                }
            });
            System.out.println(query1);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}