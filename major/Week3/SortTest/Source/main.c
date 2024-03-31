#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/main.h"
//插入, 归并, 快速(递归), 计数和基数

int main() {
    struct timespec start, end;
    double elapsed_time;

    //原型数据
    int* arr_100 = generateRandomArray(100);//小数据
    int* arr_10000 = generateRandomArray(10000);
    int* arr_50000 = generateRandomArray(50000);
    int* arr_200000 = generateRandomArray(200000);
    //临时数组
    int *temp = NULL;

    while (1) {
        print();
        int choice = 0;
        scanf("%d", &choice);

        if(choice == 1) {
            printf("InsertSorting for an array of size 10000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 10000);
            copyArray(arr_10000, temp, 10000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            InsertSort(temp, 10000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }
        if (choice == 2) {
            printf("InsertSorting for an array of size 50000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 50000);
            copyArray(arr_50000, temp, 50000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            InsertSort(temp, 50000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }

        if (choice == 3) {
            printf("InsertSorting for an array of size 200000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 200000);

            copyArray(arr_200000, temp, 200000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            InsertSort(temp, 200000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }


        /**************************/

        if (choice == 4) {
            printf("MergeSorting for an array of size 10000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 10000);
            copyArray(arr_10000, temp, 10000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            MergeSort(temp, 0, 9999);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }
        if (choice == 5) {
            printf("MergeSorting for an array of size 50000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 50000);
            copyArray(arr_50000, temp, 50000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            MergeSort(temp, 0, 49999);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }

        if(choice == 6) {
            printf("MergeSorting for an array of size 200000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 200000);

            copyArray(arr_200000, temp, 200000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            MergeSort(temp, 0, 199999);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
        }

        /**************************/


        if(choice == 7 ) {
            printf("QuickSorting for an array of size 10000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 10000);
            copyArray(arr_10000, temp, 10000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            QuickSort(temp, 0, 9999);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }

        if( choice == 8) {
            printf("QuickSorting for an array of size 50000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 50000);
            copyArray(arr_50000, temp, 50000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            QuickSort(temp, 0, 49999);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }

        if (choice == 9) {
            printf("QuickSorting for an array of size 200000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 200000);

            copyArray(arr_200000, temp, 200000);
            QuickSort(temp, 0, 199999);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
        }
        /**************************/
        if (choice == 10) {
            printf("CountSorting for an array of size 10000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 10000);
            copyArray(arr_10000, temp, 10000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            CountSort(temp, 10000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }

        if (choice == 11) {
            printf("CountSorting for an array of size 50000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 50000);
            copyArray(arr_50000, temp, 50000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            CountSort(temp, 50000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }

        if (choice == 12) {
            printf("CountSorting for an array of size 200000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 200000);
            copyArray(arr_200000, temp, 200000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            CountSort(temp, 200000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }
        /**************************/

        if (choice == 13) {
            printf("RadixCountSorting for an array of size 10000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 10000);
            copyArray(arr_10000, temp, 10000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            RadixCountSort(temp, 10000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }

        if (choice == 14) {
            printf("RadixCountSorting for an array of size 50000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 50000);
            copyArray(arr_50000, temp, 50000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            RadixCountSort(temp, 50000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n", elapsed_time);
            free(temp);
        }

        if (choice == 15) {
            printf("RadixCountSorting for an array of size 200000 is running...\n");
            temp = (int *) malloc(sizeof(int) * 200000);
            copyArray(arr_200000, temp, 200000);
            clock_gettime(CLOCK_MONOTONIC, &start);
            RadixCountSort(temp, 200000);
            clock_gettime(CLOCK_MONOTONIC, &end);

            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

            printf("Execution time: %f seconds\n\n\n",
                   elapsed_time);
            free(temp);
        }

        if(choice == 16) {
            printf("Sort an array of size 100 100k times\n\n");
            printf("Insertion running...\n");
            clock_gettime(CLOCK_MONOTONIC, &start);
            for (int i = 0; i < 100000; ++i) {
                temp = (int *) malloc(sizeof(int) * 100);
                copyArray(arr_100, temp, 100);
                InsertSort(temp, 99);
                free(temp);
            }
            clock_gettime(CLOCK_MONOTONIC, &end);
            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
            printf("Execution time: %f seconds\n------------------------\n\n", elapsed_time);
        }

        if (choice == 17) {
            printf("Merging running...\n");
            clock_gettime(CLOCK_MONOTONIC, &start);
            for (int i = 0; i < 100000; ++i) {
                temp = (int *) malloc(sizeof(int) * 100);
                copyArray(arr_100, temp, 100);
                MergeSort(temp, 0, 99);
                free(temp);
            }
            clock_gettime(CLOCK_MONOTONIC, &end);
            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
            printf("Execution time: %f seconds\n------------------------\n\n", elapsed_time);
        }

        if(choice == 18) {
            printf("Quick running...\n");
            clock_gettime(CLOCK_MONOTONIC, &start);
            for (int i = 0; i < 100000; ++i) {
                temp = (int *) malloc(sizeof(int) * 100);
                QuickSort(temp, 0, 99);
                free(temp);
            }
            clock_gettime(CLOCK_MONOTONIC, &end);
            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
            printf("Execution time: %f seconds\n------------------------\n\n", elapsed_time);
        }

        if (choice == 19){
        printf("Count running...\n");
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < 100000; ++i) {
            temp = (int *) malloc(sizeof(int) * 100);
            copyArray(arr_100, temp, 100);
            CountSort(temp, 99);
            free(temp);
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("Execution time: %f seconds\n------------------------\n\n", elapsed_time);
        }

        if (choice == 20) {
            printf("RadixCount running...\n");
            clock_gettime(CLOCK_MONOTONIC, &start);
            for (int i = 0; i < 100000; ++i) {
                temp = (int *) malloc(sizeof(int) * 100);
                copyArray(arr_100, temp, 100);
                RadixCountSort(temp, 99);
                free(temp);
            }
            clock_gettime(CLOCK_MONOTONIC, &end);
            elapsed_time = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
            printf("Execution time: %f seconds\n------------------------\n\n", elapsed_time);
        }
        if (choice > 20 || choice < 0){
            printf("invalid choice!\n");
        }
        if (choice == 0){
            free(arr_10000);
            free(arr_50000);
            free(arr_200000);
            free(arr_100);
            return 0;
        }
        system("pause");
        system("cls");
    }
}
void print() {
    printf("Welcome to the Sorting Program!\n");
    printf("Please select the sorting method and data size:\n");
    printf("1. Insertion Sort - 10000 data\n");
    printf("2. Insertion Sort - 50000 data\n");
    printf("3. Insertion Sort - 200000 data\n");
    printf("4. Merge Sort - 10000 data\n");
    printf("5. Merge Sort - 50000 data\n");
    printf("6. Merge Sort - 200000 data\n");
    printf("7. Quick Sort - 10000 data\n");
    printf("8. Quick Sort - 50000 data\n");
    printf("9. Quick Sort - 200000 data\n");
    printf("10. Counting Sort - 10000 data\n");
    printf("11. Counting Sort - 50000 data\n");
    printf("12. Counting Sort - 200000 data\n");
    printf("13. Radix Sort - 10000 data\n");
    printf("14. Radix Sort - 50000 data\n");
    printf("15. Radix Sort - 200000 data\n");
    printf("16. Insertion Sort - 100 data for 100k times\n");
    printf("17. Merge Sort - 100 data for 100k times\n");
    printf("18. Quick Sort - 100 data for 100k times\n");
    printf("19. Counting Sort - 100 data for 100k times\n");
    printf("20. RadixCount Sort - 100 data for 100k times\n");
    printf("0 --> exit\n");
    printf("Please enter the option number (0-20):\n");
}

int* generateRandomArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10001; // 生成0-10000之间的随机数
    }

    return arr;
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

//插入排序
void InsertSort(int nums[], int size) {
    // 外循环->已排序区间为 0->i-1
    for (int i = 1; i < size; i++) {
        int base = nums[i], j = i - 1;
        // 内循环->base 插入到已排序区间中的正确位置
        while (j >= 0 && nums[j] > base) {
            //移动
            nums[j + 1] = nums[j];
            j--;
        }
        // 将 base 赋值到插入位置
        nums[j + 1] = base;
    }
}

/* 合并左子数组和右子数组 */
void merge(int *nums, int left, int mid, int right) {
    // 左子数组区间为 [left, mid], 右子数组区间为 [mid+1, right]
    // 创建一个临时数组 tmp ，用于存放合并后的结果
    int tmpSize = right - left + 1;
    int *tmp = (int *)malloc(tmpSize * sizeof(int));
    // 初始化左子数组和右子数组的起始索引
    int i = left, j = mid + 1, k = 0;
    // 当左右子数组都还有元素时，进行比较并将较小的元素复制到临时数组中
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }
    // 将左子数组和右子数组的剩余元素复制到临时数组中
    while (i <= mid) {
        tmp[k++] = nums[i++];
    }
    while (j <= right) {
        tmp[k++] = nums[j++];
    }
    // 将临时数组 tmp 中的元素复制回原数组 nums 的对应区间
    for (k = 0; k < tmpSize; ++k) {
        nums[left + k] = tmp[k];
    }
    // 释放内存
    free(tmp);
}

//归并排序
void MergeSort(int *nums, int left, int right) {
    // 终止条件
    if (left >= right)
        return; // 当子数组长度为 1 时终止递归
    // 划分阶段
    int mid = (left + right) / 2;    // 计算中点
    MergeSort(nums, left, mid);      // 递归左子数组
    MergeSort(nums, mid + 1, right); // 递归右子数组
    // 合并阶段
    merge(nums, left, mid, right);
}

void swap(int nums[], int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(int nums[], int left, int right) {
    //基准数定为nums[left]
    int i = left, j = right;
    while (i < j) {
        /*
         * 注意此处, 不能从左往右找再从右往左找, 在极端情况下如果先从左往右->i一直找不到比
         * 基准数大的数->刚刚好最后一个数比基准数大->跳出外循环之后基准数和i位置的交换->将一个比基准数大的数
         * 换到数组左边->排序失败.
         *
         * 如果先从右往左, 即使j一直找不到比基准数小的数,走到最后也只是走到基准数的位置, 不影响.
         */
        while (i < j && nums[j] >= nums[left]) {
            //j从右到左找比基准数小的数
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            //i从左到右找比基准数大的数
            i++;
        }
        //找到一组, 交换一组
        swap(nums, i, j);

    }
    //走完外循环,i 和 j 重合, 将基准数换到这个位置
    //到此, 基准数左边都是比自己小的数, 右边都是比自己大的数
    swap(nums, i, left);
    //返回基准数索引
    return i;
}

void QuickSort(int nums[], int left, int right) {
    //递归终点
    if (left >= right) {
        return;
    }
    //哨兵划分
    int x = partition(nums, left, right);
    // 递归左子数组、右子数组
    QuickSort(nums, left, x - 1);
    QuickSort(nums, x + 1, right);
}

void CountSort(int nums[], int size) {
    //找最大数m
    int m = nums[0];
    for (int i = 1; i < size; ++i) {
        if (nums[i] > m){
            m = nums[i];
        }
    }

    //分配内存
    int *count = (int*) calloc(m + 1, sizeof(int ));

    //记录每个数字出现的次数
    for (int i = 0; i < size; ++i) {
        count[nums[i]]++;
    }

    //计算前缀和, 将count[nums[i]] - 1转化为 "索引对应数字在结果数组最后一次出现的尾索引"
    for (int i = 0; i < m ; ++i) {
        count[i + 1] += count[i];
    }

    //倒序遍历nums数组, 将结果放到res数组
    int* res = (int* ) malloc(sizeof (int ) * size);
    for (int i = size - 1; i >=0 ; --i) {
        res[count[nums[i]]] = nums[i];
        count[nums[i]]--;
    }

    //保存结果
    for (int i = 0; i < size; ++i) {
        nums[i] = res[i];
    }
    //有分配就有释放
    free(count);
    free(res);
}

int GetDigit(int num, int exp) {
    return (num / exp) % 10;
}

void CountSortByDigit(int nums[], int size, int exp) {
    //0-9, 做一个10int大小的数组存放每个数字出现的次数
    int *count = (int*) calloc(10, sizeof(int ));

    //统计出现次数
    for (int i = 0; i < size; ++i) {
        int digit = GetDigit(nums[i], exp);
        count[digit]++;
    }

    //计算前缀和, 将count[nums[i]] - 1转化为 "索引对应数字在结果数组最后一次出现的尾索引"
    for (int i = 0; i < 9; ++i) {
        count[i + 1] += count[i];
    }

    //倒序遍历nums数组, 将结果放到res数组
    int* res = (int* ) malloc(sizeof (int ) * size);
    for (int i = size - 1; i >=0 ; --i) {
        int digit = GetDigit(nums[i], exp);
        int index = count[digit] - 1;
        res[index] = nums[i];
        count[digit]--;
    }

    //保存结果
    for (int i = 0; i < size; ++i) {
        nums[i] = res[i];
    }

    free(count);
    free(res);
}

/* 基数排序 */
void RadixCountSort(int nums[], int size) {
    // 获取数组的最大元素，用于判断最大位数
    int max = nums[0];
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    // 按照从低位到高位的顺序遍历
    for (int exp = 1; max >= exp; exp *= 10)
        // 对数组元素的第 k 位执行计数排序
        CountSortByDigit(nums, size, exp);
}















