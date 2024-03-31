#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    const char *filename = "data.txt"; // 文件名

    // 打开文件
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("open file: %s failed\n", filename);
        system("pause");
        return 1;
    }

    // 定位到文件末尾
    fseek(file, 0, SEEK_END);

    // 获取当前文件位置（即文件大小）
    long fileSize = ftell(file);

    if (fileSize == 0) {
        printf("%s is empty.\n", filename);
        system("pause");
        return 1;
    }

    //文件指针复位
    rewind(file);

    int number;
    int lineNumber = 0;

    // 读取文件中的数据
    while (fscanf(file, "%d", &number) == 1) {
        ++lineNumber;//统计数组元素个数
    }

    rewind(file);

    //根据size读取文件, 放到一个大数组

    int size = 0;
    int *src = NULL;
    while (1) {
        while (1) {
            printf("loading data and putting data in one array\n"
                   "please input the size of data you want to load from data.txt(0 for exit):");
            scanf("%d", &size);
            if (size > lineNumber) {
                printf("Size too big! Now the total of data is: %d , input a smaller size ", lineNumber);
            } else if (size < 0) {
                printf("invalid input!");
            } else if (size == 0){
                // 关闭文件
                fclose(file);
                free(src);
                return 0;
            } else break;
        }
        src = (int *) malloc(sizeof(int) * size);
        for (int i = 0; i < size; ++i) {
            fscanf(file, "%d", &src[i]);
        }
        Sort(src, size);
    }
}

void Sort(int src[], int size) {
    //插入, 归并, 快速, 计数, 基数
    int choice = 0;
    int *temp = (int*) calloc(size, sizeof(int ));
    while (1) {
        printf("1. InsertSort\n2. MergeSort\n3. QuickSort\n4. CountSort\n5. RadixCountSort\n6. return\nchoose:");
        //做一个临时数组
        for (int i = 0; i < size; ++i) {
            temp[i] = src[i];
        }

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("InsertSort Running\n");
                InsertSort(temp, size);
                print(temp, size);
                break;
            case 2:
                printf("MergeSort Running\n");
                MergeSort(temp, 0, size - 1);
                print(temp, size);
                break;
            case 3:
                printf("QuickSort Running\n");
                QuickSort(temp, 0, size - 1);
                print(temp, size);
                break;
            case 4:
                printf("CountSort Running\n");
                CountSort(temp, size);
                print(temp, size);
                break;
            case 5:
                printf("RadixCountSort Running\n");
                RadixCountSort(temp, size);
                print(temp, size);
                break;
            case 6:
                free(temp);
                return;
            default:
                printf("invalid choice!");
        }
        system("pause");
        system("cls");
    }
}

void print(int nums[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\n", nums[i]);
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
    int m = 0;
    for (int i = 0; i < size; ++i) {
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
        res[count[nums[i]] - 1] = nums[i];
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