#include<stdio.h>
int num1[21][21];
int num2[21][21];
int main()
{
    int M,N;
    scanf("%d%d",&M,&N);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&num1[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            num2[i][j]=num1[j][i];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M-1;j++){
            printf("%d ",num2[i][j]);
        }
        printf("%d",num2[i][M-1]);
        printf("\n");
    }
    return 0;
}