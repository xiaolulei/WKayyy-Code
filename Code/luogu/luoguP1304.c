#include<stdio.h>
#include<math.h>
int zhishu(int a);
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=4;i<=N;i+=2){
        for(int j=2;j<=i/2;j++){
            if((zhishu(j)+zhishu(i-j))==2){
                printf("%d=%d+%d\n",i,j,i-j);
                break;
            } 
        }   
    }
    return 0;
}
int zhishu(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return 0;
    }
    return 1;
}