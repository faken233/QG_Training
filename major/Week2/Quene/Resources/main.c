#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../Header/LQueue.h"

void printMenu(){
    printf("\nQueue Operation Menu\n");
    printf("1. initialize queue\n");
    printf("2. Enqueue\n");
    printf("3. Dequeue\n");
    printf("4. Destroy Queue(queue needed to be reinitialized)\n");
    printf("5. Clean Queue\n");
    printf("6. Show Queue(From head to rear)\n");
    printf("7. Show length\n");
    printf("8. Show Head\n");
    printf("9. Exit\n");
    printf("Select one function:");
}
size_t size;
char *datatype;
int main() {

    LQueue *lQueue = NULL;
    char choice;
    do {
        void *data;
        printMenu();
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case '1':
                InitLQueue(&lQueue);
                break;
            case '2':
                if (lQueue == NULL){
                    printf("\nnot initialized!\n");
                    break;
                }
                printf("\ninput your data:");
                data = malloc(sizeof(10));
                if (strcmp("char", datatype) == 0) scanf("%s", (char *) data);
                if (strcmp("int", datatype) == 0) scanf("%d", (int*)data);
                if (strcmp("float", datatype) == 0) scanf("%f", (float *)data);
                fflush(stdin);
                if(EnLQueue(lQueue, data))printf("\nSuccess!\n");
                break;
            case '3':
                if(DeLQueue(lQueue))printf("\nSuccess!\n");
                break;
            case '4':
                DestroyLQueue(&lQueue);
                printf("\nalready destroy queue!\n");
                break;
            case '5':
                ClearLQueue(lQueue);
                printf("\nalready clear queue!\n");
                break;
            case '6':
                printf("\ndata as follow\n----->\n");
                TraverseLQueue(lQueue, LPrint);
                break;
            case '7':
                printf("\nlength:%zd\n", LengthLQueue(lQueue));
                break;
            case '8':
                if(GetHeadLQueue(lQueue, data) == MYFALSE){
                    break;
                }
                if (strcmp("char", datatype) == 0) printf("\nfront data:%s", (char*)data);
                if (strcmp("int", datatype) == 0) printf("\nfront data:%d", *(int*)data);
                if (strcmp("float", datatype) == 0) printf("\nfront data:%.2f", *(float *)data);
                break;
            case '9':
                printf("\n\ngoodbye!");
                Sleep(1500);
                exit(0);
            default:
                printf("\ninvalid choice!");
        }
        Sleep(1500);
        system("cls");
    } while (1);
}
