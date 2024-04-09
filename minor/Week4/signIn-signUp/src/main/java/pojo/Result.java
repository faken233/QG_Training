package pojo;

public class Result {
    private Integer code;
    private Object data;
    private String msg;

    public Result(Integer code, Object data, String msg) {
        this.code = code;
        this.data = data;
        this.msg = msg;
    }

    public Result() {
    }

    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public static Result success(String msg) {
        return new Result(1, null, msg);
    }

    public static Result success(Object data, String msg) {
        return new Result(1, data, msg);
    }

    public static Result error(String msg) {
        return new Result(0, null, msg);
    }
}
