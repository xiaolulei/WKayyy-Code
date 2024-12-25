#include<stdio.h>
long long jiecheng(int n);
int main()
{
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=n;i>0;i--){
        sum+=jiecheng(i);
    }
    printf("%lld\n",sum);
    return 0;
}
long long jiecheng(int n){  
    long long sum=1;
    for(int i=n;i>0;i--){
        sum*=i;
    }
    return sum;
}