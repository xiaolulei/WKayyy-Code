#include <stdio.h>

/**
 * 希尔排序函数 (Shell Sort)
 * * @param arr 待排序的数组
 * @param n 数组元素的数量
 */
void shellSort(int arr[], int n) {
    // 1. 设置初始间隔 (gap)：通常从 n/2 开始，每次减半，直到 gap = 1
    int gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        
        // 2. 对每个子序列进行 插入排序
        // i 从 gap 开始，遍历子序列中的元素
        for (int i = gap; i < n; i++) {
            
            // temp 存储当前子序列要插入的值
            int temp = arr[i];
            
            // j 是用来比较和移动元素的索引
            int j;
            
            // 3. 插入排序的核心步骤（移动元素）
            // 注意这里的比较步长是 gap，而不是 1
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                // 将 arr[j - gap] 移动到 arr[j] 的位置
                arr[j] = arr[j - gap];
            }
            
            // 4. 插入 temp 到正确的位置
            arr[j] = temp;
        }
    }
}

// 打印数组的辅助函数
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 主函数示例
int main() {
    int arr[] = {12, 34, 54, 2, 3, 15, 88, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("原始数组: ");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("排序后的数组: ");
    printArray(arr, n);
    
    return 0;
}
