package org.example.pojo;

import java.sql.Timestamp;
import java.time.LocalDateTime;

public class User {
    private int id;
    private String name;
    private int age;
    private String dept;
    private Timestamp createTime;

    public User() {
    }

    public User(int id, String name, int age, String dept, Timestamp createTime) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.dept = dept;
        this.createTime = createTime;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getDept() {
        return dept;
    }

    public void setDept(String dept) {
        this.dept = dept;
    }

    public Timestamp getCreateTime() {
        return createTime;
    }

    public void setCreateTime(Timestamp createTime) {
        this.createTime = createTime;
    }
}
