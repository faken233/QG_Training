package pojo;

import java.sql.Date;
import java.time.LocalDate;

public class User {
    private String userId;
    private String username;
    private int userScore;
    private Date createTime;

    public User(String id, String username, int userScore, Date createTime) {
        this.userId = id;
        this.username = username;
        this.userScore = userScore;
        this.createTime = createTime;
    }

    @Override
    public String toString() {
        return "User{" +
                "userid=" + userId +
                ", username='" + username + '\'' +
                ", userScore='" + userScore + '\'' +
                ", createTime=" + createTime +
                '}';
    }

    public User() {
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public int getUserScore() {
        return userScore;
    }

    public void setUserScore(int userScore) {
        this.userScore = userScore;
    }

    public Date getCreateTime() {
        return createTime;
    }

    public void setCreateTime(Date createTime) {
        this.createTime = createTime;
    }
}
