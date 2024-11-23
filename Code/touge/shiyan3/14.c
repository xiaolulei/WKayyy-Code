//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
int main(){
    int a;
    char b[2];
    while(scanf("%d%s",&a,b)==2){
        for(int i=1;i<=a;i++){
            for(int j=2*i-1;j>0;j--){
            printf("%c",b[0]);
            }
            printf("\n");
        }
        for(int z=a-1;z>0;z--){
            for(int j=2*z-1;j>0;j--){
            printf("%c",b[0]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}