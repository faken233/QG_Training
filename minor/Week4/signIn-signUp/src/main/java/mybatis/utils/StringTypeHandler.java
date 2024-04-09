package mybatis.utils;

import mybatis.iface.TypeHandler;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class StringTypeHandler implements TypeHandler<String> {

    @Override
    public void setParam(PreparedStatement statement, int index, String value) throws SQLException {
        statement.setString(index, value);
    }

    @Override
    public String getResult(ResultSet rs, String columnName) throws SQLException {
        return rs.getString(columnName);
    }
}
