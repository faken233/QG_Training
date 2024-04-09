package connectionpool;

import java.sql.Connection;

public class ConnectionEntity {
    private Connection connection;
    private Long UseStartTime;

    public ConnectionEntity() {
    }

    public ConnectionEntity(Connection connection, Long useStartTime) {
        this.connection = connection;
        UseStartTime = useStartTime;
    }

    public Connection getConnection() {
        return connection;
    }

    public void setConnection(Connection connection) {
        this.connection = connection;
    }

    public Long getUseStartTime() {
        return UseStartTime;
    }

    public void setUseStartTime(Long useStartTime) {
        UseStartTime = useStartTime;
    }
}
