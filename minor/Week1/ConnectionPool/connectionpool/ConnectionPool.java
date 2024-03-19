package connectionpool;

import config.DataSourceConfig;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Vector;


//实现类
public class ConnectionPool implements MyConnectionPool {

    private int connectionCount = 0;

    //存放空闲连接
    Vector<Connection> connectionsFree = new Vector<>();
    //存放正在使用的连接
    Vector<Connection> connectionsUsed = new Vector<>();

    public ConnectionPool() throws SQLException, ClassNotFoundException {
        for (int i = 0; i < Integer.parseInt(DataSourceConfig.getInitSize()); i++) {
            connectionsFree.add(createConnection());
        }
        System.out.println("初始化连接池,创建" + DataSourceConfig.getInitSize() + "个连接:" + connectionsFree);
    }

    public synchronized Connection createConnection() throws ClassNotFoundException, SQLException {
        Class.forName(DataSourceConfig.getDriver());
        Connection connection = DriverManager.getConnection(DataSourceConfig.getUrl(), DataSourceConfig.getUsername(), DataSourceConfig.getPassword());
        connectionCount++;
        return connection;
    }

    @Override
    public synchronized Connection getConnection() throws SQLException, ClassNotFoundException, InterruptedException {
        Connection connection = null;
        //判断是否有空闲连接
        if (!connectionsFree.isEmpty()) {
            //还有空余连接
            connection = connectionsFree.get(0);
            //从空闲池移除
            connectionsFree.remove(0);
            //加入正在使用的连接池
            connectionsUsed.add(connection);
            System.out.println("从空闲连接池获取一个连接:" + connection + ",现在空闲连接数为"
                    + connectionsFree.size());
            return connection;
        } else {
            //没有空闲的
            //判断当前总连接数是否大于最大数
            if (connectionCount < Integer.parseInt(DataSourceConfig.getMaxSize())) {
                //总连接数没到最大数
                connection = createConnection();
                //创建完,直接放进正在使用的连接池
                connectionsUsed.add(connection);
                System.out.println("无空闲连接,已创建新连接:" + connection + ", 现在总连接数为" + connectionCount);
                return connection;
            } else {
                //总链接数大于最大数
                System.out.println("无空闲连接且正在使用连接数大于最大数!进行等待...");
                this.wait(Integer.parseInt(DataSourceConfig.getWaitTime()));
                //递归,再次尝试
                connection = getConnection();
            }
        }
        return connection;
    }

    @Override
    public synchronized void releaseConnection(Connection connection) {
        //放入空闲连接池
        connectionsUsed.remove(connection);
        //唤醒正在等待
        notifyAll();
        connectionsFree.add(connection);
        System.out.println("一个连接完成工作,回到空闲状态,现在空余连接数为:" + connectionsFree.size() + "正在使用的连接数为" + connectionsUsed.size());
    }
}
