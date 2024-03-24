#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;//栈顶节点
	int	count;//节点数
}LinkStack;



//链栈
Status initLStack(LinkStack **s);//初始化栈
int isEmptyLStack(LinkStack *s);//判断栈是否为空
StackNode *getTopLStack(LinkStack *s);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
int LStackLength(LinkStack *s);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
int popLStack(LinkStack *s);//出栈
Status showStack(LinkStack *s);


#endif 
