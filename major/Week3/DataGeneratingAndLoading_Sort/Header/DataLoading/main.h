//
// Created by 何松 on 2024/3/31.
//

#ifndef WEEK3_LOADANDSORT_MAIN_H
#define WEEK3_LOADANDSORT_MAIN_H
void Sort(int *pInt, int size);
void print(int nums[], int size);

/*
 * 插入排序
 */
void InsertSort(int nums[], int size);

/*
 * 归并排序
 */
void merge(int *nums, int left, int mid, int right);//合并操作
void MergeSort(int *nums, int left, int right);

/*
 * 快速排序
 */
void swap(int nums[], int i, int j);//交换
int partition(int nums[], int i, int j);//哨兵划分,返回基准数索引
void QuickSort(int nums[], int left, int right);

/*
 * 计数排序
 */
void CountSort(int nums[], int size);

/*
 * 基数排序
 */
int GetDigit(int num, int exp);//获取num的k位数字, exp = 10 ^ (k - 1)
void CountSortByDigit(int nums[], int size, int exp);//根据数组中元素的第k位元素排序
void RadixCountSort(int nums[], int size);
#endif //WEEK3_LOADANDSORT_MAIN_H
