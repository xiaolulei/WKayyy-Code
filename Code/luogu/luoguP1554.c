#include<stdio.h>
int num[11];
void fenli(int i);
int main()
{
    int M,N;
    scanf("%d%d",&M,&N);
    for(int i=M;i<=N;i++){
        fenli(i);
    }
    for(int i=0;i<=8;i++){
        printf("%d ",num[i]);
    }
    printf("%d",num[9]);
    return 0;
}
void fenli(int i){
    while(i!=0){
        int n=i%10;
        i=i/10;
        num[n]++;
    }
}