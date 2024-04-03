package org.example.utils;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;


@FunctionalInterface
public interface MyHandler<T> {
    T handleResultSet(ResultSet resultSet) throws SQLException;
}
