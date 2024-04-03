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
import java.sql.SQLException;



@WebServlet("/user")
public class UserController extends HttpServlet {
    private UserServive userServive = new UserServiceImpl();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("application/json");
        resp.setHeader("Access-Control-Allow-Origin", "*");
        String res;
        String id = req.getParameter("id");
        System.out.println(id);
        User user;
        try {
            user = userServive.selectById(Integer.parseInt(id));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        if (user.getDept() == null) {
            res = JSON.toJSONString(Result.error());
        }else {
            res = JSON.toJSONString(Result.success(user));
        }
        PrintWriter writer = resp.getWriter();
        writer.write(res);
        writer.flush();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        User user = new User();
        user.setId(Integer.parseInt(req.getParameter("id")));
        user.setName(req.getParameter("name"));
        user.setAge(Integer.parseInt(req.getParameter("age")));
        user.setDept(req.getParameter("dept"));
        try {
            userServive.insert(user);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        String res = JSON.toJSONString(Result.success());
        PrintWriter writer = resp.getWriter();
        writer.write(res);
        writer.flush();
    }
}
