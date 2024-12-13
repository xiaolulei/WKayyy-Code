#include<stdio.h>
int judge(int year);
int main()
{
    int x,y;
    int sum=0;
    int year[2000];
    scanf("%d%d",&x,&y);
    for(int i=x;i<=y;i++){
        int temp=judge(i);
        if(temp){
            year[sum]=i;
            sum++;
        }
    }
    printf("%d\n",sum);
    if(sum==0){
        return 0;
    }
    if(sum>1){
    for(int i=0;i<sum-1;i++){
        printf("%d ",year[i]);
    }
    printf("%d",year[sum-1]);
    }
    else printf("%d",year[0]);
    return 0;
}
int judge(int year){
    if((year%4==0&&year%100!=0)||(year%400==0)){
        return 1;
    }
    else return 0;
}