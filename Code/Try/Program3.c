#include<stdio.h>
int caculate(int a,int n);
int main()
{
    int a,n;
    scanf("%d%d",&a,&n);
    int sum=0;
    for(int i=n;i>=0;i--){
        sum+=caculate(a,i);
    }
    printf("%d",sum);
    return 0;
}
int caculate(int a,int n){
    int sum=0;
    for(int i=n;i>1;i--){
        sum+=a;
        sum*=10;
    }
    sum+=a;
    return sum;
}