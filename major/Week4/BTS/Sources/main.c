#include <stdio.h>
#include "binary_sort_tree.h"
#include <stdlib.h>


// Print operations related to binary trees
void printBinaryTreeOperations() {
    printf("Binary Tree Operations:\n");
    printf("1. Initialization\n");
    printf("2. Insert\n");
    printf("3. Delete\n");
    printf("4. Search\n");
    printf("5. Recursive Pre-order Traversal\n");
    printf("6. Recursive In-order Traversal\n");
    printf("7. Recursive Post-order Traversal\n");
    printf("8. Iterative Pre-order Traversal\n");
    printf("9. Iterative In-order Traversal\n");
    printf("10. Iterative Post-order Traversal\n");
    printf("11. exit\n");
    printf("choose one:");
}


int main() {
    BinarySortTreePtr binarySortTreePtr = NULL;
    int choice;
    int num;
    while (1) {
        printBinaryTreeOperations();
        scanf("%d%*c", &choice);
        switch (choice) {
            case 1:
                if (binarySortTreePtr == NULL) {
                    BST_init(&binarySortTreePtr);
                    printf("initialized...\n");
                }else printf("already initialized!\n");
                system("pause");
                system("cls");
                break;
            case 2:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("please input a int to be inserted:");
                scanf("%d%*c", &num);
                BST_insert(binarySortTreePtr, num);
                system("pause");
                system("cls");
                break;
            case 3:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("please input the int you want to delete in BST:");
                scanf("%d%*c", &num);
                BST_delete(binarySortTreePtr, num);
                system("pause");
                system("cls");
                break;
            case 4:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("please input the int you want to search for:");
                scanf("%d%*c", &num);
                if(BST_search(binarySortTreePtr, num) == succeed) {
                    printf("succeed!\n");
                } else {
                    printf("not found\n");
                }
                system("pause");
                system("cls");
                break;
            case 5:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                BST_preorderR(binarySortTreePtr->root, visit);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 6:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                BST_inorderR(binarySortTreePtr->root, visit);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 7:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                BST_postorderR(binarySortTreePtr->root, visit);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 8:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                BST_preorderI(binarySortTreePtr, visit);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 9:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                BST_inorderI(binarySortTreePtr, visit);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 10:
                if (binarySortTreePtr == NULL) {
                    printf("not initialized!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                BST_postorderI(binarySortTreePtr, visit);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 11:
                exit(0);
            default:
                printf("invalid choice!\n");
                system("pause");
                system("cls");
        }
    }

}

























