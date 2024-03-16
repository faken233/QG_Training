#include <stdio.h>
#include <stdlib.h>
#include "../Headers/linkedList.h"

int main() {
    printf("Hello, World!\n");
    return 0;
}

Status InitList(LinkedList *L){
    //判断*L是否为空节点
    if(!*L){
        return ERROR;
    }
    //分配
    (*L) = (LinkedList) malloc(sizeof (LNode));

    if((*L) == NULL){
        //内存不足
        printf("内寸不足\n");
        return OVERFLOW;
    }
    //将头节点的指针域置为Null
    (*L)-> next = NULL;

    printf("成功初始化头节点");
    return SUCCESS;
}

void DestroyList(LinkedList *L){
    //初始化指针p为第一个节点
    LNode *p = (*L) -> next;

    //进入循环
    while (p -> next != NULL){
        //如果当前节点的下一节点不为Null, 则free, 遍历下一个节点
        LNode *temp = p;
        p = p -> next;
        free(temp);
    }

    //最后释放头节点
    free(*L);
}

Status InsertList(LNode *p, LNode *q){
    //检查数据
    if(p == NULL || q == NULL){
        printf("节点数据异常\n");
        return ERROR;
    }
    //插入的节点指向插入位置后面的节点
    q -> next = p -> next;
    //前一个节点指向被插入的节点
    p -> next = q;

    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType *e){
    //检查数据
    if(p == NULL){
        printf("节点数据异常\n");
        return ERROR;
    }

    //找到p的下一节点,如果是NULL则返回SUCCESS
    if (p -> next == NULL){
        printf("要删除的节点已经为NULL, 不会进行对e的赋值\n");
    } else{
        //记录删除节点
        LNode *temp = p -> next;

        //断开连接
        p -> next = p -> next -> next;

        //赋值
        (*e) = temp->data;

        //释放空间
        free(temp);
    }

    return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e)){
    LinkedList p = L -> next;
    while (p) {
        visit(p -> data);
    }
}

Status SearchList(LinkedList L, ElemType e){
    //检查数据
    if(L->next == NULL){
        printf("空链表\n");
        return ERROR;
    }
    //初始化
    LinkedList p = L->next;
    //进入循环开始遍历
    while(p != NULL){
        //找到节点,打印提示信息并跳出循环
        if(p->data == e){
            printf("找到值为%d的节点\n",e);
            return SUCCESS;
        }
        //否则遍历下一节点
        p = p->next;
    }
    //如果运行到此处时,p为NULL,说明没有找到节点
    if (p == NULL){
        printf("未找到节点\n");
        return ERROR;
    }
}

