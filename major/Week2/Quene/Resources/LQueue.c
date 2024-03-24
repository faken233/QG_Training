//
// Created by 何松 on 2024/3/23.
//
#include "../Header/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern size_t size;
extern char *datatype;

void InitLQueue(LQueue **Q){
    if((*Q) != NULL){
        printf("Queue has been initialized!\n");
        return;
    }
    //分配, 初始化
    (*Q) = (LQueue*) malloc(sizeof (LQueue));
    (*Q)->front = NULL;
    (*Q)->rear  = NULL;
    (*Q)->length = 0;
    //确定类型, 确定单个数据字节数, 顺便记录数据类型
    Datatype datatype1[3] =  {MYINT, MYFLOAT, MYCHAR};
    int choice;
    while (1) {
        printf("please type 0,1 or 2 your data type---0 for INT///1 for float/// 2 for char:");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 0 || choice == 1 || choice == 2) {
            size = datatype1[choice];
            datatype = (char*) malloc(100 * sizeof (char *));
            datatype = choice == 0 ? "int" : choice == 1 ? "float" : "char";
            break;
        } else printf("invalid choice!\n");
    }
    printf("initialize completed...\n");
}

void DestroyLQueue(LQueue **Q){
    if (*Q == NULL){
        printf("not initialized!\n");
        return;
    }

    Node *p = (*Q)->front;
    //p->next为NULL, 即释放全部节点后, 释放Q, 需要再次初始化
    while (p != NULL){
        Node *temp = p;
        p = p->next;
        free(temp);
    }
    //牢记, free之后赋值为NULL
    free(*Q);
    *Q = NULL;
}

Status IsEmptyLQueue(const LQueue *Q){
    if (Q == NULL){
        printf("not initialized!\n");
        return MYTRUE;
    }
    //三目运算, length为0则返回1
    return Q->length == 0 ? MYTRUE : MYFALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e){
    if (Q == NULL || Q->length == 0){
        printf("empty or not initialized!\n");
        return MYFALSE;
    }
    //调用memcpy, 实现真正的泛型编程,读取Q->front->data的地址,
    //将后面size个字节的数据复制到相应的e开头的地址存储
    //而size会在主干程序上进行校对和赋值,匹配数据类型的实际字节大小
    memcpy(e, Q->front->data, size);
    return MYTRUE;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    if (Q == NULL || Q->length == 0){
        printf("empty or not initialized!\n");
        return MYTRUE;
    }
    Node *p = Q->front;
    while (p != NULL){
        foo(p->data);
        p = p->next;
    }

    return MYTRUE;
}

void LPrint(void *q){
    if (strcmp("char", datatype) == 0) {
        printf("%s ", (char*)q);
    } else
    if (strcmp("int", datatype) == 0) {
        printf("%d ", *(int*)q);
    } else
    if (strcmp("float", datatype) == 0) {
        printf("%.2f ", *(float *)q);
    }
}

size_t LengthLQueue(LQueue *Q){
    if (Q == NULL){
        printf("not initialized!\n");
        return -1;
    }
    return Q->length;
}

Status EnLQueue(LQueue *Q, void *data){
    if (Q == NULL) {
        return MYFALSE;
    }
    //包装
    Node *p = (Node*) malloc(sizeof(Node));
    p->data = malloc(sizeof(size));
    //复制
    //可以通过判断选择的数据类型来判断是否输入正确形式的data, 碍于时间没有检查
    memcpy(p->data, data, sizeof(size ));

    //更新个数
    Q->length++;
    if(Q->length == 1){
        //第一个节点
        Q->rear = Q->front = p;
        p->next = NULL;
        return MYTRUE;
    }
    //更新指针域
    p->next = Q->front;
    Q->front = p;

    return MYTRUE;
}

Status DeLQueue(LQueue *Q){
    if (Q == NULL) {
        printf("not initialized!\n");
        return MYFALSE;
    } else if (Q->length == 0){
        printf("empty queue!\n");
        return MYFALSE;
    }
    printf("%d %d",*(int *)(Q->front->data), *(int *)(Q->rear->data));
    //需要找到队尾前一个节点
    Node *p = Q->front;
    Node *q = Q->rear;

    if(q == p){
        //一个节点,直接释放
        free(p->data);
        free(p);

        //更新指针域
        Q->front = Q->rear = NULL;

        //更新个数
        Q->length--;
        return MYTRUE;
    }
    //遍历直到找到原队尾元素的前一个元素
    while (p->next != q){
        p = p->next;
    }
    //释放,更新指针域,更新个数
    free(q->data);
    free(q);
    Q->rear = p;
    p->next = NULL;
    Q->length--;

    return MYTRUE;
}

Status ClearLQueue(LQueue *Q){
    if (Q == NULL || Q->length == 0){
        printf("empty or not initialized!\n");
        return MYFALSE;
    }
    Node *p = (Q)->front;
    //p->next为NULL, 即释放全部节点
    while (p != NULL){
        Node *temp = p;
        p = p->next;
        free(temp);
    }
    Q->length = 0;
    Q->front = Q->rear = NULL;
    return MYTRUE;
}

































