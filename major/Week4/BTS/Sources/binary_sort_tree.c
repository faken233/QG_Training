//
// Created by 何松 on 2024/4/6.
//
#include "binary_sort_tree.h"
#include <stdlib.h>
#include <stdio.h>

Status BST_init(BinarySortTreePtr* binarySortTreePtr) {
    (*binarySortTreePtr) = (BinarySortTreePtr ) malloc(sizeof(BinarySortTree));
    (*binarySortTreePtr)->root = NULL;
    return succeed;
}

Status BST_insert(BinarySortTreePtr binarySortTreePtr, ElemType e) {
    //位置指针
    Node* pos = binarySortTreePtr->root;
    //封装一个新节点
    Node* new = (NodePtr) malloc(sizeof(Node));
    new->value = e;
    new->left = NULL;
    new->right = NULL;

    //空树
    if (pos == NULL) {
        binarySortTreePtr->root = new;
        return succeed;
    }

    while (1) {
        if (e < pos->value) {
            if (pos->left == NULL) {
                pos->left = new;
                break;
            } else pos = pos->left;
            continue;
        } else if (e > pos->value) {
            if (pos->right == NULL) {
                pos->right = new;
                break;
            } else pos = pos->right;
            continue;
        }else if (e == pos->value) {
            free(new);
            return succeed;
        }
    }
}


Status BST_delete(BinarySortTreePtr binarySortTreePtr, ElemType e) {
    if (binarySortTreePtr->root == NULL) return failed; // 空树

    Node* pre = NULL;
    Node* cur = binarySortTreePtr->root;

    //找到要删除的节点和其父节点
    while (cur != NULL && cur->value != e) {
        pre = cur;
        if (cur->value > e) {
            cur = cur->left;
        } else cur = cur->right;
    }

    //没找到
    if (cur == NULL) return failed;

    //度=2
    if(cur->left != NULL && cur->right != NULL) {
        //从右子数找直接后继(比删除节点值大的,最小的节点)
        Node* minInRight = cur->right;
        Node* minInRightPre = cur;
        while (minInRight->left != NULL) {
            minInRightPre = minInRight;
            minInRight = minInRightPre->left;
        }

        //将直接后继的节点值复制到删除节点处
        cur->value = minInRight->value;

        //删除位置变为直接后继的节点, 直接后继节点一定没有左子节点, 故需要处理直接后继节点的右子树,让父节点指向右子树
        if (minInRightPre->left == minInRight) {
            //删除位置在父节点左边
            minInRightPre->left = minInRight->right;
        } else {
            //右边
            minInRightPre->right = minInRight->right;
        }
        free(minInRight);
    }else {
        // 度=1&&度=0
        Node *child = (cur->left != NULL) ? cur->left : cur->right;

        if (pre == NULL) {
            // 要删除的节点是根节点
            binarySortTreePtr->root = child;
        } else if (pre->left == cur) {
            pre->left = child;
        } else {
            pre->right = child;
        }
        free(cur);
    }
    return succeed;
}

Status BST_search(BinarySortTreePtr binarySortTreePtr, ElemType e) {
    Node* p = binarySortTreePtr->root;
    while (p != NULL) {
        if (p->value == e) {
            break;
        } else if (p->value > e) {
            p = p->left;
        } else if (p->value < e) {
            p = p->right;
        }
    }

    if (p == NULL) {
        return failed;
    } else return succeed;
}

Status BST_levelOrder(BinarySortTreePtr binarySortTreePtr, void (*visit)(NodePtr)) {
    if (binarySortTreePtr == NULL || binarySortTreePtr->root == NULL) return false;
    NodePtr* queue = (NodePtr*) malloc(sizeof (Node*) * 500);//辅助队列
    int front = 0, rear = 0;//队列头尾索引
    Node* cur;

    //根节点入队
    queue[rear++] = binarySortTreePtr->root;

    while (front < rear) {
        cur = queue[front++];
        visit(cur);
        //左右子节点入队
        if (cur->left != NULL) {
            queue[rear++] = cur->left;
        }
        if (cur->right != NULL) {
            queue[rear++] = cur->right;
        }
    }
    free(queue);
    return succeed;
}

void visit(Node* node){
    printf("%d ", node->value);
}

void BST_preorderR(NodePtr node, void (*visit)(NodePtr)) {
    if (node == NULL) {
        return;
    }

    visit(node);
    BST_preorderR(node->left,visit);
    BST_preorderR(node->right, visit);
}

void BST_inorderR(NodePtr node, void (*visit)(NodePtr)) {
    if (node == NULL) {
        return;
    }

    BST_inorderR(node->left, visit);
    visit(node);
    BST_inorderR(node->right, visit);
}

void BST_postorderR(NodePtr node, void (*visit)(NodePtr)) {
    if (node == NULL) {
        return;
    }

    BST_postorderR(node->left, visit);
    BST_postorderR(node->right, visit);
    visit(node);
}

void BST_preorderI(BinarySortTreePtr binarySortTreePtr, void (*visit)(NodePtr)) {
    if (binarySortTreePtr == NULL) return;
    if (binarySortTreePtr->root == NULL) {
        printf("empty tree!\n");
        return;
    }
    //初始化数组作为栈
    Node** arrStack = (Node**) calloc(20,sizeof(Node*));
    int index = -1;
    //根节点放入第一个位置
    arrStack[++index] = binarySortTreePtr->root;

    while (index != -1) {
        //出栈
        Node *p = arrStack[index];
        arrStack[index--] = NULL;
        visit(p);
        //将出栈节点的右左子节点入栈
        if (p->right != NULL)arrStack[++index] = p->right;
        if (p->left != NULL)arrStack[++index] = p->left;
    }
    free(arrStack);
}

void BST_inorderI(BinarySortTreePtr binarySortTreePtr, void (*visit)(NodePtr)) {
    if (binarySortTreePtr == NULL) return;
    if (binarySortTreePtr->root == NULL) {
        printf("empty tree!\n");
        return;
    }
    // 初始化数组作为栈
    Node** arrStack = (Node**) calloc(20, sizeof(Node*));
    int index = -1;
    Node* p = binarySortTreePtr->root;
    while (p != NULL) {
        arrStack[++index] = p;
        p = p->left;
    }

    while (index != -1) {
        // 出栈并访问当前节点
        p = arrStack[index--];
        visit(p);

        // 切换到当前节点的右子节点
        p = p->right;

        // 将当前节点及其所有左子节点依次入栈
        while (p != NULL) {
            arrStack[++index] = p;
            p = p->left;
        }
    }
    free(arrStack); // 释放动态分配的内存
}

void BST_postorderI(BinarySortTreePtr binarySortTreePtr, void (*visit)(NodePtr)) {
    if (binarySortTreePtr == NULL) return;
    if (binarySortTreePtr->root == NULL) {
        printf("empty tree!\n");
        return;
    }

    // 第一个栈用于辅助后序遍历
    Node** arrStack1 = (Node**) calloc(20, sizeof(Node*));
    int index1 = -1;

    // 第二个栈用于存储最终的后序遍历结果
    Node** arrStack2 = (Node**) calloc(20, sizeof(Node*));
    int index2 = -1;

    arrStack1[++index1] = binarySortTreePtr->root;

    // 后序遍历的过程，将遍历结果存储到arrStack2中
    while (index1 != -1) {
        Node* p = arrStack1[index1];
        arrStack1[index1--] = NULL;
        arrStack2[++index2] = p;

        if (p->left != NULL) {
            arrStack1[++index1] = p->left;
        }
        if (p->right != NULL) {
            arrStack1[++index1] = p->right;
        }
    }

    // 遍历arrStack2，实现后序遍历结果的访问
    while (index2 != -1) {
        Node* p = arrStack2[index2--];
        visit(p);
    }

    free(arrStack1); // 释放动态分配的内存
    free(arrStack2); // 释放动态分配的内存
}



































