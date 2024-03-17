#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

Status InitList(LinkedList *L){
    //判断*L是否为空节点
    if(*L){
        printf("错误\n");
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

    printf("成功初始化头节点\n");
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

Status InsertList(LinkedList L, ElemType e, LNode *q){
    //检查数据
    if(q == NULL)return ERROR;
    LNode *p = L;
    int key = 0;
    while (p != NULL){
        if (p->data == e){
            key = 1;
            break;
        }
        p = p->next;
    }
    if (key == 1)
    //插入的节点指向插入位置后面的节点
    {
        q -> next = p -> next;
        //前一个节点指向被插入的节点
        p -> next = q;
        return SUCCESS;
    } else return ERROR;

}

Status AddList(LinkedList L, LNode *p){
    //头插法
    //检查
    if(L == NULL)return ERROR;
    p->next = L->next;
    L->next = p;

    return SUCCESS;
}

LinkedList createNode(ElemType e){
    LinkedList p = (LinkedList) malloc(sizeof(LNode));
    p->next = NULL;
    p->data = e;
    return p;
}

Status DeleteList(LinkedList L, ElemType e){
    //检查数据
    if(L == NULL || L->next == NULL){
        return ERROR;
    }
    //初始化,p记录删除节点的前一个节点
    LNode *p = L;
    while (p->next != NULL){
        if (p->next->data == e){
            break;
        }
        p = p->next;
    }
    //如果找到了要删除的节点,进入循环
    if (p->next->data == e){
        //记录删除节点
        LNode *temp = p -> next;

        //断开连接
        p -> next = p -> next -> next;

        //赋值
        (e) = temp->data;

        //释放空间
        free(temp);
    }

    return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e)){
    if(L == NULL || L->next == NULL)return;
    LinkedList p = L -> next;
    while (p) {
        visit(p -> data);
        p = p->next;
    }
}

LNode *SearchList(LinkedList L, ElemType e){
    //检查数据
    if(L->next == NULL){
        printf("空链表\n");
        return NULL;
    }
    //初始化
    LinkedList p = L->next;
    //进入循环开始遍历
    while(p != NULL){
        //找到节点,打印提示信息并跳出循环
        if(p->data == e){
            printf("找到值为%d的节点\n",e);
            return p;
        }
        //否则遍历下一节点
        p = p->next;
    }
    //如果运行到此处时,p为NULL,说明没有找到节点
    if (p == NULL){
        printf("未找到节点\n");
        return NULL;
    }
    return NULL;
}

//非递归,迭代法
Status ReverseList(LinkedList *L){
    //检查链表是否为未初始化链表或者已经初始化但从未添加节点的或者单个节点的链表
    if ((*L) == NULL || (*L)->next == NULL || (*L)->next->next == NULL){
        printf("链表不满足反转要求");
        return ERROR;
    }
    // 初始化三个指针
    // 一个为pre:记录前一个节点信息
    // 一个为cur:记录当前节点信息
    // 一个为next:记录下一个节点信息
    LinkedList pre, cur, next;
    pre = NULL;
    cur = (*L)->next;

    //进入循环
    for(; cur != NULL; ){
        next = cur->next;
        cur->next = pre;
        pre = cur;

        cur = next;
    }
    //让L指向反转后的头节点
    (*L)->next = pre;
    return SUCCESS;
}

LinkedList ReverseListByRecursion(LinkedList L){
    //空链表或者单个节点的链表直接返回
    //其次,进入递归后当递归到最后一个节点,返回原先链表的尾节点
    if(L == NULL || L->next == NULL){
        return L;
    }
    LinkedList last = ReverseListByRecursion(L->next);
    //核心代码
    L->next->next = L;
    L->next = NULL;
    return last;
}

void ShowList(LinkedList L){
    if(L == NULL || L->next == NULL){
        printf("空链表\n");
        return;
    }
    LinkedList p = L->next;
    while (p != NULL){
        printf("%d -> ",p->data);
        if(p->next == NULL)printf("NULL");
        p = p->next;
    }
    printf("\n");
}

Status IsLoopList(LinkedList L){
    //检查
    if (L == NULL){
        return ERROR;
    }

    LinkedList p,q;
    p = q = L;
    //p每次走一个,q每次走两个
    //如果是单链表,走得快的q会先走到尾节点或者倒数第二个节点
    //此处使用三目表达式避免q->next出现空指针异常
    while (q->next == NULL ? 0 : (q->next->next) == NULL ? 0 : 1){
        p = p->next;
        q = q->next->next;
        if (p == q){
            return SUCCESS;
        }
    }
    return ERROR;
}

Status ReverseEvenList(LinkedList L){
    //检查
    //链表至少要有两个节点
    if(L == NULL)return ERROR;
    if(L->next == NULL)return ERROR;
    if(L->next->next == NULL)return ERROR;
    //初始化,并且让头节点指向原本在第二个的节点q
//    LinkedList p,q;
//    p = L->next, q = L->next->next;
//    L->next = q;
//
//    //节点数根据奇偶分为两种情况,
//    while (q->next == NULL ? 0 : (q->next->next == NULL ? 0 : 1)){
//        //反转奇偶
//        p->next = q->next;
//        q->next = p;
//        //后移
//        p = p->next;
//        q = p->next;
//    }
//    return SUCCESS;
    LinkedList prev = L->next; // 前驱节点，初始为哨兵节点的next指针指向的节点
    LinkedList p = prev->next; // 当前处理的奇数位置节点
    LinkedList q = p->next; // 当前处理的偶数位置节点

    while (q != NULL && q->next != NULL) {
        prev->next = q; // 更新前驱节点指向偶数位置节点
        p->next = q->next; // 奇数位置节点指向下一个奇数位置节点
        q->next = p; // 偶数位置节点指向奇数位置节点
        prev = p; // 更新前驱节点
        p = p->next; // 移动到下一个奇数位置节点
        q = p != NULL ? p->next : NULL; // 移动到下一个偶数位置节点
    }

    return SUCCESS;
}

LNode* FindMidNode(LinkedList *L){
    //检查
    //单个节点的链表直接返回
    if((*L) == NULL)return NULL;
    if((*L) -> next == NULL)return NULL;
    if((*L)->next->next == NULL)return (*L)->next;

    //初始化
    LinkedList p,q;
    p = (*L)->next, q = (*L)->next->next;

    //同判断循环链表, p走一,q走二,当q本身为NULL或者q->next为NULL时p应在中间位置
    while (q == NULL ? 0 : (q->next == NULL ? 0 : 1)){
        p = p->next,q = q->next->next;
    }
    return p;
}






