package mybatis.utils;

import mybatis.iface.TokenHandler;

/**
 * @author Clinton Begin
 * Tips:
 * 本人已经一行行分析代码, 并且根据个人理解做了相应的注释.
 */
public class GenericTokenParser {

  private final String openToken;
  private final String closeToken;
  private final TokenHandler handler;

  public GenericTokenParser(String openToken, String closeToken, TokenHandler handler) {
    this.openToken = openToken;
    this.closeToken = closeToken;
    this.handler = handler;
  }

  public String parse(String text) {
    if (text == null || text.isEmpty()) {
      return "";
    }

    //寻找初始标记, 找不到则返回原文本, 找到了则返回标记的位置
    int start = text.indexOf(openToken);
    if (start == -1) {
      return text;
    }

    //将文本转换为字符数组方便处理, 设置offset(偏移量)
    //设置builder存放原字符串转化成的字符数组
    // expression存放解析到的字符内容(如#{xx}内的xx)
    char[] src = text.toCharArray();
    int offset = 0;
    final StringBuilder builder = new StringBuilder();
    StringBuilder expression = null;

    //
    while (start > -1) {
      if (start > 0 && src[start - 1] == '\\') {
        // 在标记符号前有转义符号, 移除反斜杠, 重置offset继续循环
        builder.append(src, offset, start - offset - 1).append(openToken);
        offset = start + openToken.length();
      } else {
        // 找到了标记符号, 寻找结束符号

        //刷新expression
        if (expression == null) {
          expression = new StringBuilder();
        } else {
          expression.setLength(0);
        }

        //builder拼接, 设置offset到标记字符后第一个字符的索引
        builder.append(src, offset, start - offset);
        offset = start + openToken.length();

        //寻找结束字符
        int end = text.indexOf(closeToken, offset);
        while (end > -1) {
          if (end > offset && src[end - 1] == '\\') {
            // 在结束符号前有转义符号, 移除反斜杠, 重置offset继续循环
            expression.append(src, offset, end - offset - 1).append(closeToken);
            offset = end + closeToken.length();
            end = text.indexOf(closeToken, offset);
          } else {
            //将标记符号和结束符号内的内容提取赋值给expression, 准备交给handler处理
            expression.append(src, offset, end - offset);
            offset = end + closeToken.length();
            break;
          }
        }
        if (end == -1) {
          // 没找到结束字符, 返回原字符串
          builder.append(src, start, src.length - start);
          offset = src.length;
        } else {
          //处理expression, 处理结果拼接回builder
          builder.append(handler.handleToken(expression.toString()));
          offset = end + closeToken.length();
        }
      }
      //重置start,寻找下一个起始字符
      //
      start = text.indexOf(openToken, offset);
    }
    if (offset < src.length) {
      builder.append(src, offset, src.length - offset);
    }
    return builder.toString();
  }
}
