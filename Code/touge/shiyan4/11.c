#include <stdio.h>
#include <stdlib.h>
char my_result(int x) {
    if (x == 11)
        return 'J';
    else if (x == 12)
        return 'Q';
    else if (x == 13)
        return 'K';
    else if (x == 14)
        return 'A';
    else
        return '?';
}

int main() {
    int N = 0, a = 0, b = 0, c = 0, i, j, k, t;
    int data[100];
    char o1, p, z;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d%c %d%c %d%c", &a, &o1, &b, &p, &c, &z);
        data[0] = a;
        data[1] = b;
        data[2] = c;
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2 - j; k++) {
                if (data[k] > data[k + 1]) {
                    t = data[k];
                    data[k] = data[k + 1];
                    data[k + 1] = t;
                }
            }
        }
        if (data[0] == data[1] && data[1] == data[2]) {
            if (data[2] < 11 && data[2] > 1)
                printf("Leopard %d\n", data[2]);
            else if (data[2] >= 11 && data[2] <= 14) {
                char result = my_result(data[2]);
                printf("Leopard %c\n", result);
            }
        }
        else if (o1 == p && p == z && data[2] - data[1] == 1 && data[1] - data[0] == 1) {
            if (data[2] < 11 && data[2] > 1)
                printf("Flush straight %d\n", data[2]);
            else if (data[2] >= 11 && data[2] <= 14) {
                char result = my_result(data[2]);
                printf("Flush straight %c\n", result);
            }
        }
        else if (data[2] - data[1] == 1 && data[1] - data[0] == 1) {
            if (data[2] < 11 && data[2] > 1)
                printf("Straight %d\n", data[2]);
            else if (data[2] >= 11 && data[2] <= 14) {
                char result = my_result(data[2]);
                printf("Straight %c\n", result);
            }
        }
        else {
            printf("High card %d %d %d\n", data[0], data[1], data[2]);
        }
    }
    return 0;
}