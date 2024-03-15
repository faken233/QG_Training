#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

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
    //插入的节点指向插入位置后面的节点
    q -> next = p -> next;
    //前一个节点指向被插入的节点
    p -> next = q;

    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType *e);

void TraverseList(LinkedList L, void (*visit)(ElemType e)){
    LinkedList p = L -> next;
    while (p) {
        visit(p -> data);
    }
}
