#include <stdio.h>
typedef long long int LL;
int main() {
    LL n,x;
    LL num= 0, sum= 0;
    scanf("%lld", &n);
    for (LL i = 1; i <= n; i++) {
        scanf("%lld",&x);
        sum += (x*x);
        num+=x;
    }
    printf("%lld",(num*num-sum)/2);
    return 0;
}