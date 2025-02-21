#include <stdio.h>

// 正确示例：交换指针所指向的值
void correct_swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    long long num1 = 10;
    long long num2 = 20;

    printf("交换前: num1 = %lld, num2 = %lld\n", num1, num2);
    correct_swap(&num1, &num2);
    printf("交换后: num1 = %lld, num2 = %lld\n", num1, num2);

    return 0;
}