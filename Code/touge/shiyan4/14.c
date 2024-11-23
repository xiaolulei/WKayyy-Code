#include <stdio.h>
int a(long long n);
int main() {
    long long N;
    scanf("%lld",&N);
    int sum=a(N);
    while (sum>9) {
        sum=a(sum);
    }
    printf("%d\n",sum);
    return 0;
}
int a(long long n) {
    int sum=0;
    while (n>0) {
        sum+=n%10;
        n/=10;
    }
    return sum;
}