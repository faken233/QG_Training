package reqDemo;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/req7")
public class req7_Unauthorized extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //读取请求参数的username
        String username = req.getParameter("username");
        if (username.equals("zhangsan")){
            System.out.println("User zhangsan is unauthorized!");
            resp.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
        }else {
            System.out.println("User " + username + " is authorized!");
            resp.setStatus(HttpServletResponse.SC_OK);
        }
    }
}
