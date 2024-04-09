package mybatis.utils;

import mybatis.iface.TokenHandler;

import java.util.ArrayList;
import java.util.List;

public class ParameterMappingTokenHandler implements TokenHandler {

    private List<ParameterMapping> parameterMappings = new ArrayList<>();

    @Override
    public String handleToken(String content) {
        parameterMappings.add(new ParameterMapping(content));
        return "?";
    }

    public List<ParameterMapping> getParameterMappings() {
        return parameterMappings;
    }
}
