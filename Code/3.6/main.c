#include<stdio.h>

int main() {
    char a[1000], b = 0;
    int sum = 0;
    printf("请输入你要输入几个字符:");
    scanf("%d", &sum);

    // 清除输入缓冲区中的换行符
    while (getchar() != '\n') continue;

    for (int i = 0; i < sum; i++) {
        scanf("%c", &a[i]);
        if (i > 0) {
            if (a[i] > b) {
                b = a[i];
            }
        } else {
            b = a[i]; // 初始化b为第一个输入的字符
        }
    }

    printf("%c\n", b);
    return 0;
}
