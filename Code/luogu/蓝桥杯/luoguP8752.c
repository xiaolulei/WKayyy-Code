#include<stdio.h>
int judge(int n);
int main()
{
    int a[5],sum=0;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        if(judge(a[i])){
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}

int judge(int n){
    int ge,shi,bai,qian;
    ge=n%10;
    shi=(n/10)%10;
    bai=(n/100)%10;
    qian=n/1000;
    if(qian==shi&&ge==(bai+1)){
        return 1;
    }
    else return 0;
}