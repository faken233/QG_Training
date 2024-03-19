import connectionpool.ConnectionPool;
import org.junit.Test;

import java.sql.Connection;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        Thread1 t1 = new Thread1();
        for (int i = 0; i < 8; i++) {
            new Thread(t1, "线程" + i).start();
        }
    }


    static class Thread1 implements Runnable {
        @Override
        public void run() {
            try {
                Connection connection = DataSourceManager.getConnection();
                Thread.sleep(1000);
                DataSourceManager.releaseConnection(connection);
            } catch (SQLException e) {
                throw new RuntimeException(e);
            } catch (ClassNotFoundException e) {
                throw new RuntimeException(e);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}