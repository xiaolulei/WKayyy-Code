#include<stdio.h>
int a[101] = { 0 }, b[101] = { 0 };
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int h = i; h > 0; h--) {
            if (a[h] < a[i])
                b[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
            printf("%d ", b[i]);
        }
    return 0;
}