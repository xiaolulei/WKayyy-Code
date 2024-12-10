#include<stdio.h>
int A[11][11],B[11][11],C[11][11];
int main()
{
    int M,N,P;
    scanf("%d%d%d",&M,&N,&P);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            scanf("%d",&B[i][j]);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<P;j++){
            
        }
    }
    return 0;
}