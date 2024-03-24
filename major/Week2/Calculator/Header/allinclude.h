//
// Created by 何松 on 2024/3/23.
//

#ifndef CACULATE_ALLINCLUDE_H
#define CACULATE_ALLINCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//顺序结构实现栈 以及函数接口
/*************/
typedef struct
{
    char data[100];
    int count;
} OperatorStack;


void initStack();//初始化
int Push(char opt);//入栈
int Pop();//出栈, 返回操作成功与否的状态码
char Peek();//出栈,返回出栈元素
char getEleTop();//不出栈,返回栈顶元素
int isEmpty();//判断是否为空栈
/*******/

//功能函数接口
/*********/
int opt(char signal);//运算符优先级比较
float calculateTopTwoEle(float firstValue, float secondValue, char signal);//栈顶元素运算
int isValid(char express[]);//表达式有效性判断

/*********/

//链式结构实现栈以及函数接口
/*********/
typedef struct Node
{
    float data;
    struct Node * next;
} Node, *LinkList;

void initNumStack();//初始化
void PushNum(float data);//入栈
float PeekNum();//出栈
int isEmptyNum();//是否为空栈
/**********/




#endif //CACULATE_ALLINCLUDE_H
