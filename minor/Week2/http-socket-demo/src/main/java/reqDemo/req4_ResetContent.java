package reqDemo;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Arrays;
import java.util.Map;

@WebServlet("/req4")
public class req4_ResetContent extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //获取参数,封装到Map,在控制台遍历输出
        Map<String, String[]> parameterMap = req.getParameterMap();
        System.out.println(parameterMap);
        parameterMap.forEach((k, v) -> System.out.println(k + "->" + Arrays.toString(v)));
        //返回205, 清空表单
        resp.setStatus(HttpServletResponse.SC_RESET_CONTENT);
    }
}
