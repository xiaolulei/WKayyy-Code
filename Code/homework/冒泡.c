#include <stdbool.h> // 需要包含此头文件来使用 bool 类型

/**
 * 优化后的冒泡排序函数 (Optimized Bubble Sort)
 * * @param arr 待排序的数组
 * @param n 数组元素的数量
 */
void optimizedBubbleSort(int arr[], int n) {
    int i, j;
    bool swapped; // 标志位：记录是否发生了交换

    for (i = 0; i < n - 1; i++) {
        swapped = false; // 假设本轮没有交换

        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true; // 发生了交换
            }
        }

        // 如果在内层循环中没有发生任何交换，说明数组已经有序，提前退出
        if (swapped == false) {
            break;
        }
    }
}

// 示例调用 (在 main 函数中替换 bubbleSort(arr, n);):
/*
    optimizedBubbleSort(arr, n);
    printf("排序后的数组 (优化版): ");
    printArray(arr, n);
*/
