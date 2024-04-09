package mybatis.iface;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public interface TypeHandler<T> {
    void setParam(PreparedStatement statement, int index, T value) throws SQLException;

    T getResult(ResultSet rs, String columnName) throws SQLException;
}
