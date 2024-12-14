#include<stdio.h>
int fac1(int n)
{
    if(n==1)return 1;
    else return n*fac1(n-1);
}
long long fac2(long long n)
{
    if(n==1)return 1;
    else return n*fac2(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    int sum1 = fac1(n);
    printf("%d\n",sum1);
    long long sum2 = fac2(n);
    printf("%lld\n",sum2);
    return 0;
}
// int 12
// long long 31
