//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
#include<math.h>
int main(){
    int A,B;
    int flag;
    while(scanf("%d%d",&A,&B)==2){
    for(int N=1;N<=10000;N++){
        int sqrtAN = (int)sqrt(A + N);
        int sqrtBN = (int)sqrt(B + N);
        if(sqrtAN * sqrtAN == A + N && sqrtBN * sqrtBN == B + N){
            printf("%d\n",N);
            flag=0;
            break;
        }
        else flag = 1;
    }
    if(flag)
        {
            printf("Not found!\n");

        }
    }
    return 0;
}
