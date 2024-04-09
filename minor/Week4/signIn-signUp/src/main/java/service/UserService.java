package service;

import mybatis.anno.ParamFaken;
import pojo.User;

public interface UserService {
    User selectUser(String userName, String password);
    User selectUserByName(String userName);
    int signupUser(String userName, String password) throws Exception;
    int updatePassword(@ParamFaken("password") String password, @ParamFaken("name") String name);

}
