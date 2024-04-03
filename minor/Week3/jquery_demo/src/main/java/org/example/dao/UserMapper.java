package org.example.dao;

import org.example.pojo.User;
import org.example.utils.JDBCUtils;
import org.example.utils.MyHandler;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class UserMapper {

    public User selectById(int id) throws Exception {
        String condition = "id = " + id;
        return JDBCUtils.query(condition, resultSet -> {
            User user = new User();
            while (resultSet.next()) {
                user.setId(resultSet.getInt("id"));
                user.setName(resultSet.getString("name"));
                user.setAge(resultSet.getInt("age"));
                user.setDept(resultSet.getString("dept"));
                user.setCreateTime(resultSet.getTimestamp("create_time"));
            }
            return user;
        });
    }

    public boolean insert(User user) throws SQLException {
        //获取实体类对象属性
        int userId = user.getId();
        String username = user.getName();
        int userAge = user.getAge();
        String dept = user.getDept();
        Timestamp createTime = user.getCreateTime();
        //准备sql语句
        PreparedStatement preparedStatement =JDBCUtils.getConnection().prepareStatement("insert into test3.employee "
                + " (id, name,age, dept, create_time) " +
                " values (?,?,?,?,CURRENT_TIMESTAMP)");
        //拼接
        preparedStatement.setInt(1, userId);
        preparedStatement.setString(2, username);
        preparedStatement.setInt(3, userAge);
        preparedStatement.setString(4, dept);
        //执行
        return preparedStatement.execute();
    }

    public List<User> selectAll() throws Exception {
        return JDBCUtils.query("id like '%' ", (MyHandler<List<User>>) resultSet -> {
            ArrayList<User> list = new ArrayList<>();
            while (resultSet.next()) {
                User user = new User();
                user.setId(resultSet.getInt("id"));
                user.setName(resultSet.getString("name"));
                user.setAge(resultSet.getInt("age"));
                user.setDept(resultSet.getString("dept"));
                user.setCreateTime(resultSet.getTimestamp("create_time"));
                list.add(user);
            }
            return list;
        });
    }
}
