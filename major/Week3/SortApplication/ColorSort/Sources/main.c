#include <stdio.h>
#include <malloc.h>

void swap(int nums[], int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void colorSort(int nums[], int size) {
    //初始化索引
    int p0 = 0, p2 = size - 1, temp;

    for (int p1 = 0; p1 < p2; ++p1) {
        if (nums[p1] == 0){
            //p1遍历到0, 二话不说先放左边
            swap(nums, p0, p1);
            //索引自增
            p0++;
            //再判断交换过来p1位置的是不是0或者2
            if (nums[p1] == 0) {
                swap(nums, p0, p1);
                //索引自增
                p0++;
            } else if (nums[p1] == 2) {
                swap(nums, p1, p2);
                p2--;
            }
        } else if (nums[p1] == 2) {
            swap(nums, p1, p2);
            p2--;
            if (nums[p1] == 0){
                swap(nums, p0, p1);
                //索引自增
                p0++;
            } else if (nums[p1] == 2) {
                swap(nums, p1, p2);
                p2--;
            }
        }
    }
}


int main() {
    int *a = (int*) malloc(sizeof(int) * 20);
    int size = 0;
    printf("Now is ColorSort\nHow many 0/1/2 you want to input(no more than 20):");
    scanf("%d%*c", &size);
    if (size > 20 || size <= 0) {
        printf("Illegal size!\n");
        free(a);
        system("pause");
        return 1;
    }
    printf("please input %d numbers to put into array for sort...\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d%*c", &a[i]);
    }
    //检查数据
    for (int i = 0; i < size; ++i) {
        if(a[i] != 0 && a[i] != 1 && a[i] != 2){
            printf("Illegal number appear!\n");
            free(a);
            system("pause");
            return 1;
        }
    }
    colorSort(a, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    system("pause");
}
