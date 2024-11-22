#include<stdio.h>
#include<math.h>
int sushu(int M);
int main()
{
    int M,N;
    int sum=0;
    scanf("%d%d",&M,&N);
        for(int i=M+1;sum<N;i++){
            if(sushu(i)&&sushu(i+2)){
                sum++;
                printf("%d,%d\n",i,i+2);
            }
        }
    return 0;
}
int sushu(int N)
{
    int flag=1;
    for(int i=2;i<=sqrt(N);i++){
        if(N%i==0){
            flag=0;
            return 0;
        } 
    }
    return 1;
}