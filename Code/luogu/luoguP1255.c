#include<stdio.h>
int main()
{
    int N;
    long long way[6000];
    scanf("%d",&N);
    if(N==1){
        printf("1");
        return 0;
    }
    else if(N==2){
        printf("2");
        return 0;
    }
    else{
       way[1]=1;
       way[2]=2;
       for(int i=3;i<=N;i++){
        way[i]=(way[i-1]+way[i-2]);
       } 
       printf("%lld",way[N]);
    }
    return 0;
}
