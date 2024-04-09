package service.impl;

import dao.UserMapper;
import mybatis.utils.MapperProxyFactory;
import pojo.User;
import service.UserService;

public class UserServiceImpl implements UserService {
    private final UserMapper userMapper = MapperProxyFactory.getMapper(UserMapper.class);

    public UserServiceImpl() {
    }

    @Override
    public User selectUser(String userName, String password) {
        return userMapper.selectUser(userName, password);
    }

    @Override
    public User selectUserByName(String userName) {
        return userMapper.selectUserByName(userName);
    }

    @Override
    public int signupUser(String userName, String password) throws Exception{
        return userMapper.signupUser(userName, password);
    }

    @Override
    public int updatePassword(String password, String name) {
        return userMapper.updatePassword(password, name);
    }
}
