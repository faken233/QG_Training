package config;

import connectionpool.ConnectionPool;

import java.io.FileReader;
import java.io.IOException;
import java.net.URL;
import java.util.Properties;


public class DataSourceConfig {
    public static String password;
    public static String username;
    public static String url;
    public static String driver;
    public static String initSize;
    public static String maxSize;
    public static String health;
    public static String delay;

    static {
        Properties properties = new Properties();
        try {
            ClassLoader classLoader = ConnectionPool.class.getClassLoader();
            URL resource = classLoader.getResource("properties.properties");
            if (resource != null) {
                properties.load(new FileReader(resource.getFile()));
            }
            password = properties.getProperty("jdbc.password");
            username = properties.getProperty("jdbc.username");
            url = properties.getProperty("jdbc.url");
            driver = properties.getProperty("jdbc.driver");
            initSize = properties.getProperty("jdbc.initSize");
            maxSize = properties.getProperty("jdbc.maxSize");
            health = properties.getProperty("jdbc.health");
            delay = properties.getProperty("jdbc.delay");
            period = properties.getProperty("jdbc.period");
            timeout = properties.getProperty("jdbc.timeout");
            waitTime = properties.getProperty("jdbc.waitTime");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static String getPassword() {
        return password;
    }

    public static void setPassword(String password) {
        DataSourceConfig.password = password;
    }

    public static String getUsername() {
        return username;
    }

    public static void setUsername(String username) {
        DataSourceConfig.username = username;
    }

    public static String getUrl() {
        return url;
    }

    public static void setUrl(String url) {
        DataSourceConfig.url = url;
    }

    public static String getDriver() {
        return driver;
    }

    public static void setDriver(String driver) {
        DataSourceConfig.driver = driver;
    }

    public static String getInitSize() {
        return initSize;
    }

    public static void setInitSize(String initSize) {
        DataSourceConfig.initSize = initSize;
    }

    public static String getMaxSize() {
        return maxSize;
    }

    public static void setMaxSize(String maxSize) {
        DataSourceConfig.maxSize = maxSize;
    }

    public static String getHealth() {
        return health;
    }

    public static void setHealth(String health) {
        DataSourceConfig.health = health;
    }

    public static String getDelay() {
        return delay;
    }

    public static void setDelay(String delay) {
        DataSourceConfig.delay = delay;
    }

    public static String getPeriod() {
        return period;
    }

    public static void setPeriod(String period) {
        DataSourceConfig.period = period;
    }

    public static String getTimeout() {
        return timeout;
    }

    public static void setTimeout(String timeout) {
        DataSourceConfig.timeout = timeout;
    }

    public static String getWaitTime() {
        return waitTime;
    }

    public static void setWaitTime(String waitTime) {
        DataSourceConfig.waitTime = waitTime;
    }

    public static String period;
    public static String timeout;
    public static String waitTime;


    public DataSourceConfig getDataSourceConfig() {
        return this;
    }
}
