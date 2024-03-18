package Utils;

import java.sql.ResultSet;
import java.sql.SQLException;


@FunctionalInterface
public interface MyHandler<T> {
    T handleResultSet(ResultSet resultSet) throws SQLException;
}
