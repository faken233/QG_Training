package connectionpool;

import java.sql.Connection;
import java.sql.SQLException;

public interface MyConnectionPool {
    //获取一个连接对象
    Connection getConnection() throws SQLException, ClassNotFoundException, InterruptedException;

    //归还
    void releaseConnection(Connection connection);
}
