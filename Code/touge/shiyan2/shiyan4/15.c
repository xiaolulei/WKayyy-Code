#include <stdio.h>
#include <math.h>
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
        return 0;
    }
    return 1;
}

int main() {
    int a;
    scanf("%d", &a);
    int sum = ceil((float)a / 2);
    for (int i = 2; i < sum; i++) {
        int j = a - i;
        if (is_prime(i) && is_prime(j)) {
            printf("%d=%d+%d\n",a,i,j);
        }
    }
    return 0;
}