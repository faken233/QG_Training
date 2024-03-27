package reqDemo;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/req2")
public class req2_redirect extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //获取请求参数
        String parameter = "username=" + req.getParameter("username");
        String reURL = "http://localhost:8080/http_socket_demo_war/req1?" + parameter;
        resp.sendRedirect(reURL);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 从 POST 请求体中获取数据
        String postData = request.getReader().lines().reduce("", (accumulator, actual) -> accumulator + actual);

        // 构建重定向的目标 URL，包含请求参数
        String redirectURL = "http://localhost:8080/http_socket_demo_war/req1?" + postData;

        // 发送重定向
        response.sendRedirect(redirectURL);
    }
}
