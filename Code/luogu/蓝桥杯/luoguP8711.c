#include<stdio.h>
int main()
{
    long long n,temp;
    scanf("%lld",&n);
    while(n>1){
        printf("%lld ",n);
        n/=2;
    }
    printf("%lld",n);
    return 0;
}