#include <stdio.h>
int main() {
    int num, b = 0;
    scanf("%d", &num);

    while (num != 0) {
        b = b * 10 + num % 10;
        num /= 10;
    }
    printf("%d\n", b);
    return 0;
}