package org.example.service;

import org.example.pojo.User;

import java.sql.SQLException;
import java.util.List;

public interface UserServive {
    User selectById(int id) throws Exception;

    void insert(User user) throws SQLException;

    List<User> selectAll() throws Exception;
}
