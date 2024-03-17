//
// Created by 何松 on 2024/3/16.
//
#include "linkedList.h"

void printMenu();


int main(){
    int choice;
    int data;
    LinkedList L;


    do {
        printMenu();
        scanf("%d", &choice);
//        printf("\n***** 图形菜单 *****\n");
//        printf("1. 初始化链表\n");
//        printf("2. 添加节点\n");
//        printf("3. 插入节点\n");
//        printf("4. 删除节点\n");
//        printf("5. 查询节点\n");
//        printf("6. 反转链表\n");
//        printf("7. 判断链表是否成环\n");
//        printf("8. 奇偶调换\n");
//        printf("9. 查询中点\n");
//        printf("10. 显示当前链表\n");
//        printf("11. 退出\n");
//        printf("请选择操作: ");

        switch (choice) {
            case 1:
                printf("初始化链表\n");
                InitList(&L);
                break;
            case 2:
                printf("添加一个节点,请输入节点的data:");
                scanf("%d",&data);
                getchar();
                LinkedList new = createNode(data);
                AddList(L,new);
                break;
            case 3:
                printf("插入节点操作\n现在链表数据如下:\n");
                ShowList(L);
                printf("输入你准备插入的位置(即哪个节点后)的data 和插入的节点的data,例: 1 2\n请输入:");
                int position = 0;
                int inserted = 0;
                scanf("%d%d", &position, &inserted);
                LNode *inserted_node = createNode(inserted);
                InsertList(L, position, inserted_node);
                printf("操作后链表数据如下:\n");
                ShowList(L);
                break;
            case 4:
                printf("执行删除操作\n现在链表数据如下:\n");
                ShowList(L);
                printf("输入你要删除的节点data:");
                scanf("%d",&data);
                getchar();
                DeleteList(L, data);
                printf("操作后链表数据如下:\n");
                ShowList(L);
                break;
            case 5:
                printf("查询操作\n");
                printf("输入你要查找的节点数据:");
                scanf("%d",&data);
                getchar();
                LNode *pNode = SearchList(L, data);
                if (pNode->data != 0){
                    printf("查找到对应节点\n");
                } else{
                    printf("未找到此节点\n");
                }
                break;
            case 6:
                printf("反转链表\n请选择反转方法:1. 迭代法//2. 递归法\n输入你的选择:");
                scanf("%d",&data);
                getchar();
                if(data == 1){
                    ReverseList(&L);
                }else if(data == 2){
                    L->next = ReverseListByRecursion(L->next);
                }else printf("无效方法\n");
                break;
            case 7:
                printf("判断链表是否成环\n");
                Status status = IsLoopList(L);
                if(status == SUCCESS){
                    printf("是\n");
                } else printf("不是\n");
                break;
//            case 8:
//                printf("奇偶调换\n");
//                ReverseEvenList(L);
//                break;
            case 9:
                printf("查询中点\n");
                LNode *midNode = FindMidNode(&L);
                printf("中点数据为:%d\n",midNode->data);
                break;
            case 10:
                ShowList(L);
                break;
            case 11:
                exit(0);
            default:
                printf("无效的选择，请重新输入\n");
        }
    } while (choice != 0);

    return 0;
}

void printMenu() {
    printf("\n***** 图形菜单 *****\n");
    printf("1. 初始化链表\n");
    printf("2. 添加节点\n");
    printf("3. 插入节点\n");
    printf("4. 删除节点\n");
    printf("5. 查询节点\n");
    printf("6. 反转链表\n");
    printf("7. 判断链表是否成环\n");
//    printf("8. 奇偶调换\n");
    printf("9. 查询中点\n");
    printf("10. 显示当前链表\n");
    printf("11. 退出\n");
    printf("请选择操作: ");
}