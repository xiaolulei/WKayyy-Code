#include<stdio.h>
unsigned long long jiecheng(int n);
int main()
{
    int n;
    scanf("%d",&n);
    unsigned long long sum=0;
    for(int i=n;i>0;i--){
        sum+=jiecheng(i);
    }
    printf("%llu\n",sum);
    return 0;
}
unsigned long long jiecheng(int n){  
    unsigned long long sum=1;
    for(int i=n;i>0;i--){
        sum*=i;
    }
    return sum;
}