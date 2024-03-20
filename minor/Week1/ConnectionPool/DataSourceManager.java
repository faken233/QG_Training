import connectionpool.ConnectionPool;

import java.sql.Connection;
import java.sql.SQLException;

public class DataSourceManager {
    private static final ConnectionPool connectionPool;

    static {
        try {
            connectionPool = new ConnectionPool();
        } catch (SQLException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public DataSourceManager() {
    }

    public static Connection getConnection() throws SQLException, ClassNotFoundException, InterruptedException {
        return connectionPool.getConnection();
    }

    public static void releaseConnection(Connection connection) {
        connectionPool.releaseConnection(connection);
    }
}
