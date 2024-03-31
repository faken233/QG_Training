#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成指定范围内的随机数
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    int size; // 数组大小
    int minRange, maxRange; // 元素范围
    const char *filename = "data.txt"; // 文件名

    // 输入数组大小
    while (1) {
        printf("please input the size of the array:");
        scanf("%d", &size);
        if (size >= 0) {
            break;
        } else printf("size should be bigger than zero!\n");
    }

    // 输入元素范围
    while (1) {
        printf("please input the minRange and maxRange of number:");
        scanf("%d %d", &minRange, &maxRange);
        if (maxRange - minRange && maxRange > 0 && minRange > 0) {
            break;
        } else printf("maxRange should be bigger than minRange and both should be bigger than zero!\n");
    }

    // 打开文件
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return 1;
    }

    // 使用当前时间作为随机数种子
    srand(time(NULL));

    // 生成随机数并写入文件
    for (int i = 0; i < size; i++) {
        int randomNumber = generateRandomNumber(minRange, maxRange);
        fprintf(file, "%d\n", randomNumber);
    }

    // 关闭文件
    fclose(file);

    printf("Array generated and saved in %s, size: %d, min: %d, max: %d\n", filename, size, minRange, maxRange);
    system("pause");
    return 0;
}