#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 初始化随机数种子
    srand((unsigned)time(NULL));

    // 生成10个0到99之间的随机数
    for (int i = 0; i < 10; i++) {
        int random_num = rand() % 100;
        printf("%d ", random_num);
    }
    printf("\n");

    return 0;
}