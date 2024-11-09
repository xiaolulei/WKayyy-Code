//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
int main(){
    int a;
    int sum=0;
    int sum1=0,sum2=0,sum3=0;
    while(scanf("%d",&a)==1){
        if(a==1) {
            sum+=1000;
            sum1++;
        }
    
        if(a==2){ 
            sum+=500;
            sum2++;
        }
        if(a==3){
            sum+=200;
            sum3++;
        }
    }
    if(sum1>=3){
        sum+=1000;
    }
    if(sum2>=6){
        sum+=500;
    }
    if(sum3>=10){
        sum+=200;
    }
    printf("%d",sum);
    return 0;
    }
    
