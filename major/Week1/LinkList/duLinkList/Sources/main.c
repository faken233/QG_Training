//
// Created by 何松 on 2024/3/17.
//

#include "duLinkedList.h"

void printMenu();


int main(){
    int choice;
    int data;
    DuLinkedList L = NULL;
    int position;
    int inserted;


    do {
        printMenu();
        scanf("%d", &choice);
//        printf("\n***** 图形菜单 *****\n");
//        printf("1. 初始化链表\n");
//        printf("2. 添加节点\n");
//        printf("3. 前插节点\n");
//        printf("4. 后插节点\n");
//        printf("5. 删除节点\n");
//        printf("6. 显示当前链表\n");
//        printf("7. 退出\n");
//        printf("请选择操作: ");

        switch (choice) {
            case 1:
                printf("初始化链表\n");
                InitList_DuL(&L);
                break;
            case 2:
                printf("添加一个节点,请输入节点的data:");
                scanf("%d",&data);
                getchar();
                addDuNode(L,data);
                break;
            case 3:
                printf("前插节点操作\n现在链表数据如下:\n");
                TraverseList_DuL(L, *visit);
                printf("输入你准备插入的位置(即哪个节点)的data 和插入的节点的data,例: 1 2\n请输入:");
                scanf("%d%d", &position, &inserted);
                InsertBeforeList_DuL(L, position, inserted);
                printf("操作后链表数据如下:\n");
                TraverseList_DuL(L, visit);
                break;
            case 4:
                printf("后插插节点操作\n现在链表数据如下:\n");
                TraverseList_DuL(L, *visit);
                printf("输入你准备插入的位置(即哪个节点)的data 和插入的节点的data,例: 1 2\n请输入:");
                scanf("%d%d", &position, &inserted);
                InsertAfterList_DuL(L, position, inserted);
                printf("操作后链表数据如下:\n");
                TraverseList_DuL(L, *visit);
                break;
            case 5:
                printf("删除节点操作\n现在链表数据如下:\n");
                TraverseList_DuL(L, *visit);
                printf("输入你要删除的节点data:");
                scanf("%d",&data);
                DeleteList_DuL(L, data);
                printf("现在链表数据如下:\n");
                TraverseList_DuL(L, visit);
                break;
            case 6:
                printf("现在链表数据如下:\n");
                TraverseList_DuL(L, *visit);
                break;
            case 7:
                exit(0);
            default:
                printf("无效操作\n");
        }
    } while (choice != 0);

    return 0;
}

void printMenu() {
    printf("\n***** 图形菜单 *****\n");
    printf("1. 初始化链表\n");
    printf("2. 添加节点\n");
    printf("3. 前插节点\n");
    printf("4. 后插节点\n");
    printf("5. 删除节点\n");
    printf("6. 显示当前链表\n");
    printf("7. 退出\n");
    printf("请选择操作: ");
}