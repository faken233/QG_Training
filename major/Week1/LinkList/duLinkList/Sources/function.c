//
// Created by 何松 on 2024/3/16.
//
#include <stdio.h>
#include "duLinkedList.h"
#include <stdlib.h>

Status InitList_DuL(DuLinkedList *L){
    //检查是否已经进行过初始化
    if((*L) != NULL){
        printf("链表已经初始化\n");
        return ERROR;
    }

    (*L) = (DuLinkedList) malloc(sizeof(DuLNode));
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return SUCCESS;
}

void DestroyList_DuL(DuLinkedList *L){
    //检查
    if ((*L) == NULL || ((*L)->next == NULL)){
        printf("链表为空链表或者已经被Destroy\n");
        return;
    }
    DuLNode *p = (*L)->next, *temp;
    //逐个删除节点
    while (p != NULL){
        temp = p;
        p = p->next;
        free(temp);
    }
    //释放头节点
    free(*L);
    return;
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
    //检查
    if (L == NULL || L->next == NULL){
        printf("空链表\n");
        return;
    }

    DuLNode *p = L->next;
    while (p != NULL){
        visit(p->data);
        p = p->next;
    }
    if(p == NULL){
        printf("NULL\n");
    }
    return;
}

void visit(ElemType e){
    printf("%d  ", e);
}

Status InsertBeforeList_DuL(DuLinkedList L, ElemType p, ElemType q){
    //检查
    if(L == NULL || L->next == NULL){
        printf("空链表\n");
        return ERROR;
    }

    //寻找节点值为p的节点
    DuLNode *temp = L->next;
    while (temp != NULL){
        if(temp->data == p){
            break;
        }
        temp = temp->next;
    }
    //没找到
    if(temp == NULL){
        printf("未找到插入位置节点\n");
        return ERROR;
    }
    //找到了
    //1. 包装要插进去的data为q的节点
    DuLNode *insert = createDuNode(q);
    //2. 将insert节点插到p前面
    insert->next = temp;
    insert->prior = temp->prior;
    temp->prior->next = insert;
    temp->prior = insert;

    return SUCCESS;
}

Status InsertAfterList_DuL(DuLinkedList L, ElemType p, ElemType q){
    if(L == NULL || L->next == NULL){
        printf("空链表\n");
        return ERROR;
    }

    //寻找节点值为p的节点
    DuLNode *temp = L->next;
    while (temp != NULL){
        if(temp->data == p){
            break;
        }
        temp = temp->next;
    }
    //没找到
    if(temp == NULL){
        printf("未找到插入位置节点\n");
        return ERROR;
    }
    //找到了
    //1. 包装要插进去的data为q的节点
    DuLNode *insert = createDuNode(q);
    //2. 将insert节点插到p后面
    insert->prior = temp;
    insert->next = temp->next;
    temp->next->prior = insert;
    temp->next = insert;
    
    return SUCCESS;
}

Status DeleteList_DuL(DuLinkedList L, ElemType p){
    if(L == NULL || L->next == NULL){
        printf("空链表\n");
        return ERROR;
    }

    //寻找节点值为p的节点
    DuLNode *temp = L->next;
    while (temp != NULL){
        if(temp->data == p){
            break;
        }
        temp = temp->next;
    }
    //没找到
    if(temp == NULL){
        printf("未找到节点\n");
        return ERROR;
    }
    //找到节点,开始删除节点
    temp->prior->next = temp->next;
    temp->next->prior = temp->prior;
    free(temp);
    
    return SUCCESS;
}


DuLNode *createDuNode(ElemType e){
    DuLNode *newNode = (DuLNode *) malloc(sizeof(DuLNode));
    newNode->data = e;
    newNode->next = NULL;
    newNode->prior = NULL;
    return newNode;
}

Status addDuNode(DuLinkedList L, ElemType e){
    //头插法添加node
    //检查
    if(L == NULL){
        printf("未初始化链表\n");
        return ERROR;
    }
    //包装
    DuLNode *node = createDuNode(e);
    //插入
    node->prior = L;
    node->next = L->next;
    if(L->next != NULL){
        L->next->prior = node;
    }
    L->next = node;

    return SUCCESS;
}



















