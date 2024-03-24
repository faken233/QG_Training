#include <stdio.h>
#include <stdlib.h>
#include "../Head/LinkStack.h"
#include "LinkStack.c"
#include <windows.h>
void printMenu(){
    printf("---Menu of LinkStack---");
    printf("\n1. Initialize\n2. Push\n3. Pop\n4. ShowStack\n"
           "5. Clear Stack\n6. Destroy Stack(reinitialize needed)\n7. Show Length of Stack\n"
           "8. Exit\n");
}

int main(){
    LinkStack *s = NULL;
    int choice, value;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\ninitializing Stack...\n");
                initLStack(&s);
                printf("initializing succeed!\n");
                break;
            case 2:
                printf("\nEnter value to push: ");
                scanf("%d", &value);
                pushLStack(s, value);
                break;
            case 3:
                printf("\n");
                popLStack(s);
                break;
            case 4:
                printf("\n");
                showStack(s);
                break;
            case 5:
                clearLStack(s);
                break;
            case 6:
                destroyLStack(s);
                break;
            case 7:
                printf("\nlength: %d\n", LStackLength(s));
                break;
            case 8:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
        Sleep(1000);
        system("cls");
    } while (choice != 8);

    return 0;
}
