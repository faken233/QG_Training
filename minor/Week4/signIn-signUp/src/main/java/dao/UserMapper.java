package dao;

import mybatis.anno.InsertFaken;
import mybatis.anno.ParamFaken;
import mybatis.anno.SelectFaken;
import pojo.User;

public interface UserMapper {
    @SelectFaken("select * from users where name = #{userName} and password = #{password}")
    User selectUser(@ParamFaken("userName") String userName, @ParamFaken("password") String password);

    @SelectFaken("select * from users where name = #{userName}")
    User selectUserByName(@ParamFaken("userName") String userName);

    @InsertFaken("insert into users (name, password) values (#{userName}, #{password})")
    int signupUser(@ParamFaken("userName") String userName, @ParamFaken("password") String password);

    @InsertFaken("update users set password = #{password} where name = #{name}")
    int updatePassword(@ParamFaken("password") String password, @ParamFaken("name") String name);
}
