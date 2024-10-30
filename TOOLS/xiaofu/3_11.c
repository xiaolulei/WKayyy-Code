#include <stdio.h>

int main() {
    int a[11],i;
    for (i = 1; i <= 10; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 10; i >=1 ; i--) {
        printf("%d ", a[i]);
    }
    return 0;
}