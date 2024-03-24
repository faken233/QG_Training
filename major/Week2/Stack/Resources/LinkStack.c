#include "../Head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
//链栈

//初始化栈
Status initLStack(LinkStack **s){
    //分配内存
    *s = (LinkStack*) malloc(sizeof(LinkStack));
    //给节点分配
    (*s)->count = 0;
    (*s)->top = NULL;
    return SUCCESS;
}

//判断栈是否为空
int isEmptyLStack(LinkStack *s){
    return s->count == 0;
}

//得到栈顶元素
StackNode* getTopLStack(LinkStack *s){
    return s->top;
}

//清空栈
Status clearLStack(LinkStack *s){
    while (s->top){
        StackNode *p = s->top->next;
        free(s->top);
        s->top = p;
    }
}

//销毁栈
Status destroyLStack(LinkStack *s){
    while (s->top){
        StackNode *p = s->top->next;
        free(s->top);
        s->top = p;
    }
    free(s);
    s = NULL;
    return SUCCESS;
}

//检测栈长度
int LStackLength(LinkStack *s){
    if(s == NULL ? 1 : s->top == NULL ? 1 : 0){
        return 0;
    }
    return s->count;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
    //检查
    if(s == NULL){
        return ERROR;
    }
    //分配内存
    StackNode *p = (StackNode*) malloc(sizeof (StackNode));
    //更新节点指针域
    p->next = s->top;
    //更新节点数据域
    p->data = data;
    //栈顶元素更新
    s->top = p;
    //元素数量更新
    s->count++;
    return SUCCESS;
}

//出栈
int popLStack(LinkStack *s){
    if (s == NULL? 1 : s->top == NULL? 1 :0){
        return ERROR;
    }
    //记录要出栈的节点数据域
	int data = getTopLStack(s)->data;
    //记录出栈节点
    StackNode *p = getTopLStack(s);
    //更新栈顶
    s->top = s->top->next;
    //释放内存
    free(p);
    //栈节点数量更新
    s->count--;
    return data;
}

Status showStack(LinkStack *s){
    if (s == NULL? 1 : isEmptyLStack(s)? 1 :0){
        printf("initialize needed or empty stack\n");
        return ERROR;
    }
    StackNode *p = s->top;
    while (p != NULL){
        printf("|  %d  |\n", p->data);
        p = p->next;
    }
    if (p == NULL){
        printf("-------");
    }
    return SUCCESS;
}





