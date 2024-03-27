package reqDemo;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/req8")
public class req8_Head extends HttpServlet {
    @Override
    protected void doHead(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 设置响应头信息，不需要设置响应体内容
        resp.setContentLength(0); // 设置内容长度为0，因为HEAD请求不返回实际内容
        resp.setStatus(HttpServletResponse.SC_OK); // 设置状态码为200 OK
    }

    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("options");
        super.doOptions(req, resp);
    }


}
