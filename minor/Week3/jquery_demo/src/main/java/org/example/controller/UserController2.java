package org.example.controller;


import com.alibaba.fastjson.JSON;
import org.example.pojo.Result;
import org.example.pojo.User;
import org.example.service.UserServive;
import org.example.service.impl.UserServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

@WebServlet("/users")
public class UserController2 extends HttpServlet {
    private UserServive userServive = new UserServiceImpl();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        List<User> userList;
        try {
            userList = userServive.selectAll();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        resp.setHeader("Access-Control-Allow-Origin", "*");
        String res = JSON.toJSONString(Result.success(userList));
        PrintWriter writer = resp.getWriter();
        writer.write(res);
        writer.flush();
    }
}
