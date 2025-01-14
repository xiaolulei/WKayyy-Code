#include<stdio.h>

int judge(int v,int n);

int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int v=1;v<n;v++){
        if(judge(v,n)) sum++;
    }
    printf("%d\n",sum);
    return 0;
}

int judge(int v,int n){
    if(v*v%n<(n/2.0)){
        return 1;
    }
    else return 0;
}