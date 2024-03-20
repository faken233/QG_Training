import java.sql.Connection;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) {
        Thread1 t1 = new Thread1();
        for (int i = 0; i < 8; i++) {
            //开启三个线程
            new Thread(t1, "线程" + i).start();
        }
    }


    static class Thread1 implements Runnable {
        @Override
        public void run() {
            try {
                //获取连接
                Connection connection = DataSourceManager.getConnection();
                //模拟操作
                Thread.sleep(1000);
                //释放
                DataSourceManager.releaseConnection(connection);
            } catch (SQLException | ClassNotFoundException | InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}