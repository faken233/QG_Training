package servlet;

import com.alibaba.fastjson.JSON;
import pojo.Result;
import pojo.User;
import service.UserService;
import service.impl.UserServiceImpl;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@SuppressWarnings("unused")
@WebServlet("/user/*")
public class UserServletImpl extends UserBaseServlet{
    private final UserService userService = new UserServiceImpl();

    public UserServletImpl() throws ClassNotFoundException {
    }

    public void selectUser(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/json;charset=utf-8");
        String s = req.getReader().readLine();
        User user = JSON.parseObject(s, User.class);
        String userName = user.getName();
        String password = user.getPassword();
        User selected = userService.selectUser(userName, password);
        String resultJson;
        if (selected != null) {
            resultJson = JSON.toJSONString(Result.success("login_success"));
        } else {
            resultJson = JSON.toJSONString(Result.error("no_such_user"));
        }
        resp.getWriter().write(resultJson);
    }

    public void signupUser(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/json;charset=utf-8");
        String s = req.getReader().readLine();
        User user = JSON.parseObject(s, User.class);
        String userName = user.getName();
        String password = user.getPassword();
        int i = 0;
        try {
            i = userService.signupUser(userName, password);
        } catch (Exception e) {
            if (e.getCause().getMessage().contains("Duplicate entry")) {
                resp.getWriter().write(JSON.toJSONString(Result.error("existed")));
            }
            return;
        }
        String resultJson = "";
        if (i != 0) {
            resultJson = JSON.toJSONString(Result.success("success"));
        } else {
            resultJson = JSON.toJSONString(Result.error("existed"));
        }
        resp.getWriter().write(resultJson);
    }


    public void updatePassword(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/json;charset=utf-8");
        String s = req.getReader().readLine();
        User user = JSON.parseObject(s, User.class);
        String userName = user.getName();
        String newPassword = user.getPassword();
        User formerUser = userService.selectUserByName(userName);
        String resultJson = "";
        if (formerUser != null) {
            //存在此用户
            int i = userService.updatePassword(newPassword, userName);
            if (i == 1) {
                resultJson = JSON.toJSONString(Result.success("success"));
            } else {
                resultJson = JSON.toJSONString(Result.error("failed"));
            }
        }else {
            resultJson = JSON.toJSONString(Result.error("no_such_user"));
        }

        resp.getWriter().write(resultJson);
    }
}
