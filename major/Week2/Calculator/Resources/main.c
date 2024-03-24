#include "allinclude.h"

OperatorStack s;
LinkList top;

void initStack()
{
    s.count = 0;
}

int Push(char opt)
{
    if (s.count == 100)
    {
        return -1;
    }
    s.data[s.count++] = opt;

    return 1;
}

int Pop()
{
    if (s.count == 0)
    {
        return -1;
    }

    s.data[s.count - 1] = '\0';
    s.count--;
    return 1;
}

char Peek()
{
    if (s.count == 0)
    {
        return '\0';
    }

    char e = s.data[s.count - 1];
    s.data[s.count - 1] = '\0';
    s.count--;
    return e;
}

char getEleTop()
{
    if (s.count == 0)
    {
        return '\0';
    }

    char e = s.data[s.count - 1];
    return e;
}

int isEmpty()
{
    if (s.count > 0)
    {
        return 0;
    }

    return 1;
}

/**********/

void initNumStack()
{
    top = (malloc)(sizeof(Node));
    top->next = NULL;
}

void PushNum(float data)
{
    LinkList node = (malloc)(sizeof(Node));
    node->data = data;
    node->next = top->next;
    top->next = node;
}

float PeekNum()
{
    LinkList topEle = top->next;
    float data = topEle->data;
    top->next = topEle->next;
    free(topEle);
    return data;
}

int isEmptyNum()
{
    if (top->next == NULL)
    {
        return 1;
    }

    return 0;
}

/******************/
int opt(char signal)
{
    if (signal == '+' || signal == '-')
    {
        return 1;
    }
    else if (signal == '*' || signal == '/')
    {
        return 2;
    }
}

float calculateTopTwoEle(float firstValue, float secondValue, char signal) // 计算逻辑入参以及返回值改为float
{
    if (signal == '+')
    {
        return secondValue + firstValue;
    }
    else if (signal == '-')
    {
       return secondValue - firstValue;
    }
    else if (signal == '*')
    {
       return secondValue * firstValue;
    }
    else if (signal == '/')
    {
       return secondValue / firstValue;
    }

    return 0;
}

int isValid(char express[])
{
    initStack();
    int i;
    for (i = 0; i < strlen(express); i++)
    {
        char c = express[i];
        // 判断输入的表达式是否含有数字0-9 . ( ) + - * / 以外的字符。
        if (!(c >= '0' && c <= '9' || c == '.' || c == '(' || c == ')' ||
            c == '+' || c == '-' || c == '*' || c == '/'))
        {
            return 0;
        }


        // 左右括号不匹配
        if (express[i] == '(')
        {
            if (i < strlen(express) - 1 && express[i + 1] == ')')
            {// ()
               return 0;
            }
            Push('(');
        }
        else if (express[i] == ')')
        {
            if (i < strlen(express) - 1 && express[i + 1] == '(')
            { // )(
               return 0;
            }

            if (isEmpty())
            {
               return 0;
            }

            Pop();
        }
        else if (express[i] == '+' || express[i] == '*' || express[i] == '/')
        {
            // -5+6   6+5*
            if (i == 0 || i == strlen(express) - 1)
            {
                return 0;
            }

            // (+9*2)
            if (i != 0 && express[i - 1] == '(')
            {
                return 0;
            }

            // (9*2+)
            if (i < strlen(express) - 1 && express[i + 1] == ')')
            {
                return 0;
            }

            // 8++9
            if (i < strlen(express) - 1)
            {
                char nextChar = express[i + 1];
                if (nextChar == '+' || nextChar == '*' || nextChar == '/')
                {
                    return 0;
                }
                else if (nextChar == '-')
                {

                }
            }
        }
        else if (express[i] == '-')
        {

        }
    }

    if (!isEmpty())
    {
        return 0;
    }
    return 1;
}

int main()
{
    //符号压进顺序栈, 数字压进链栈
    //初始化
    initNumStack();
    char express[100];
    while (1) {
        printf("请输入合法的四则运算表达式(输入0表示结束):");
        scanf("%s", express);
        if (express[0] == '0'){
            exit(0);
        }
        //验证有效性
        int valid = isValid(express);
        if (valid == 0) {
            printf("表达式不合法！");
            return 0;
        }

        int i;
        for (i = 0; i < strlen(express); i++) {
            //元素为运算符
            if (express[i] == '+'
                || express[i] == '-' && i != 0 && express[i - 1] >= '0' && express[i - 1] <= '9'
                || express[i] == '*' || express[i] == '/') {
                if (isEmpty()) {
                    //栈空, 直接入栈, 进入下一次循环
                    Push(express[i]);
                    continue;
                }
                //非空, 如果栈顶是左括号,直接入栈, 下一次循环
                char topEle = getEleTop();
                if (topEle == '(') {
                    Push(express[i]);
                    continue;
                }
                //比较
                while (opt(topEle) >= opt(express[i]))//栈顶元素运算符优先级大于表达式当前运算符优先级,
                {
                    printf("%c ", Peek());
                    float firstValue = PeekNum();
                    float secondValue = PeekNum();
                    float result = calculateTopTwoEle(firstValue, secondValue, topEle);
                    PushNum(result);
                    topEle = getEleTop();
                }
                Push(express[i]);
            } else if (express[i] == '(')//直接入栈
            {
                Push(express[i]);
            } else if (express[i] == ')')//当前元素为右括号,找到最近一个左括号之内的转换好了的后缀表达式进行运算
            {
                char topEle = Peek();
                while (topEle != '(') {
                    printf("%c ", topEle);
                    float firstValue = PeekNum();
                    float secondValue = PeekNum();
                    float result = calculateTopTwoEle(firstValue, secondValue, topEle);
                    //结果压进链栈
                    PushNum(result);
                    //将下一个左括号出栈
                    topEle = Peek();
                }
            } else//处理到数字,先判断多位数/小数, 处理完毕后压进链栈
            {
                char num[10];
                int index = 0;
                printf("%c", express[i]);
                num[index++] = express[i];
                int j;
                int isEnd = 0;
                for (j = 1; i + j <= strlen(express); j++) {
                    if (express[i + j] >= '0' && express[i + j] <= '9' || express[i + j] == '.') {
                        printf("%c", express[i + j]);
                        num[index++] = express[i + j];
                        if (i + j == strlen(express) - 1) {
                            isEnd = 1;
                        }
                    } else {
                        i = i + j - 1;
                        printf(" ");
                        break;
                    }
                }
                num[index++] = '\0';
                float value = atof(num);
                PushNum(value);
                if (isEnd) {
                    break;
                }
            }
        }

        while (!isEmpty()) {
            char topEle = Peek();
            float firstValue = PeekNum();
            float secondValue = PeekNum();
            float result = calculateTopTwoEle(firstValue, secondValue, topEle);
            PushNum(result);
            printf("%c ", topEle);
        }

        printf("=%f", PeekNum());
        printf("\n\n");
    }
}
