#include <stdio.h>
#include <malloc.h>

int partition(int nums[], int left, int right);
void swap(int *a, int *b);
int Kth_small_num(int nums[], int K, int left, int right);
int Kth_large_num(int nums[], int K, int left, int right);


int main() {
    int size = 0;
    printf("How many numbers you want to input:");
    scanf("%d%*c", &size);

    if (size <= 0) {
        printf("Illegal size!\n");
        system("pause");
        return 1;
    }
    int *a = (int*) malloc(sizeof(int) * size);

    printf("please input %d numbers to put into array for sort...\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d%*c", &a[i]);
    }

    while (1) {
        int choice = 0;
        printf("choose your way to find the number\n1. the Kth smallest number\n2. the Kth largest number\n"
               "choose one(0 for exit):");
        scanf("%d%*c", &choice);
        if (choice != 1 && choice != 2 && choice != 0) {
            printf("invalid choice!");
            system("pause");
            system("cls");
            continue;
        } else  {
            if (choice == 0) {
                return 1;
            }
            int k = 0;
            printf("input a value for k:");
            scanf("%d%*c", &k);
            if (k >= size){
                printf("invalid k!\n");
                system("pause");
                system("cls");
                continue;
            }
            if (choice == 1) {
                int smallNum = Kth_small_num(a, k, 0, size - 1);
                printf("the %d smallest number: %d", k, smallNum);
                system("pause");
                system("cls");
                continue;
            } else if (choice == 2) {
                int largeNum = Kth_large_num(a, k, 0, size - 1);
                printf("the %d largest number: %d", k, largeNum);
                system("pause");
                system("cls");
                continue;
            }
        }
    }
}

int partition(int nums[], int left, int right) {
    int pivot = nums[left];
    int i = left, j = right;

    while (i < j) {
        while (nums[j] >= pivot && i < j) {
            j--;
        }
        while (nums[i] <= pivot && i < j) {
            i++;
        }
        swap(&nums[i], &nums[j]);
    }
    swap(&nums[i], &nums[left]);
    return i;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Kth_small_num(int nums[], int K, int left, int right) {
    if (K > 0 && K <= right - left + 1) {
        int index = partition(nums, left, right);
        if (index - left == K - 1) {
            return nums[index];
        } else if (index - left > K - 1) {
            return Kth_small_num(nums, K, left, index - 1);
        } else if (index - left < K - 1) {
            return Kth_small_num(nums, K - (index - left + 1), index + 1, right);
        }
    }
    return -1;
}

int Kth_large_num(int nums[], int K, int left, int right) {
    if (K > 0 && K <= right - left + 1) {
        int index = partition(nums, left, right);
        if (right - index == K - 1) {
            return nums[index];
        } else if (right - index > K - 1) {
            return Kth_large_num(nums, K, index + 1, right);
        } else if (right - index < K - 1) {
            return Kth_large_num(nums, K - (right - index + 1), left, index - 1);
        }
    }
    return -1;
}














