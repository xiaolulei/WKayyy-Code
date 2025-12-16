#include <stdio.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * 分区函数 (Partition)
 * 选择最后一个元素作为基准 (Pivot)，并将小于基准的元素放到其左边。
 * * @param arr 待排序的数组
 * @param low 分区的起始索引
 * @param high 分区的结束索引
 * @return 基准元素最终所在的位置 (索引)
 */
int partition(int arr[], int low, int high) {
    // 1. 选择基准 (Pivot)：这里选择最后一个元素
    int pivot = arr[high]; 
    
    // i: 较小元素 的索引，代表小于基准元素的区域的边界
    int i = (low - 1); 

    // 2. 遍历并分区
    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于基准
        if (arr[j] <= pivot) {
            // 将较小元素的索引 i 向右移动一位
            i++; 
            // 交换 arr[i] 和 arr[j]，将 arr[j] 放入小于基准的区域
            swap(&arr[i], &arr[j]);
        }
    }
    
    // 3. 将基准元素放到正确的位置 (i+1)
    swap(&arr[i + 1], &arr[high]);
    
    // 返回基准元素最终的索引
    return (i + 1);
}

/**
 * 快速排序主函数
 * * @param arr 待排序的数组
 * @param low 数组的起始索引
 * @param high 数组的结束索引
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi 是分区后基准元素 (pivot) 的索引
        int pi = partition(arr, low, high);

        // 递归对左侧子数组排序
        quickSort(arr, low, pi - 1);
        
        // 递归对右侧子数组排序
        quickSort(arr, pi + 1, high);
    }
}

// 打印数组的辅助函数
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 主函数示例
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("原始数组: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("排序后的数组: ");
    printArray(arr, n);
    
    return 0;
}
