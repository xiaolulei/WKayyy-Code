#include<stdio.h>
#include <limits.h>

long long num[100002];
long long sum[100002]={0};

int main()
{
    long long N;
    scanf("%lld",&N);
    for(int i=1;i<=N;i++){
        scanf("%lld",&num[i]);
    }
    int temp=1,temp1=0;
    for(int i=1;(temp1+=i)<=N;i*=2,temp++){
        for(int j=0;j<i;j++){
            sum[temp]+=num[j+i];
        }
    }
    long long max = LLONG_MIN;
    int min_position;
    for(int i=1;i<=temp;i++){

        if(max<sum[i]){
            max=sum[i];
            min_position=i;
        }
    }
    printf("%lld\n",min_position);
    return 0;
}