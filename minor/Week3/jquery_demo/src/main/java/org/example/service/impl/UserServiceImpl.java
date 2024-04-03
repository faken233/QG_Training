package org.example.service.impl;

import org.example.dao.UserMapper;
import org.example.pojo.User;
import org.example.service.UserServive;

import java.sql.SQLException;
import java.util.List;

public class UserServiceImpl implements UserServive {
    private final UserMapper userMapper = new UserMapper();

    @Override
    public User selectById(int id) throws Exception {
        return userMapper.selectById(id);
    }

    @Override
    public void insert(User user) throws SQLException {
        userMapper.insert(user);
    }

    @Override
    public List<User> selectAll() throws Exception {
        return userMapper.selectAll();
    }
}
