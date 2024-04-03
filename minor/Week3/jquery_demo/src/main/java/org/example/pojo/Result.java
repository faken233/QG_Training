package org.example.pojo;

public class Result {
    private String msg;
    private int code;
    private Object data;

    public Result(String msg, int code, Object data) {
        this.msg = msg;
        this.code = code;
        this.data = data;
    }

    public Result() {
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public int getCode() {
        return code;
    }

    public void setCode(int code) {
        this.code = code;
    }

    public Object getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public static Result success() {
        return new Result("success", 1, null);
    }

    public static Result success(Object data) {
        return new Result("success", 1, data);
    }

    public static Result error() {
        return new Result("error", 0, null);
    }
}
