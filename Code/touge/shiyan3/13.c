//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
int main(){
    int a,b,c;
    int sum=0;
    while(scanf("%d%d%d",&a,&b,&c)==3){
        if(a+b==c) {
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}