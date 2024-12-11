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
    for(int i=0;i<M;i++) {
        for(int j=0;j<P;j++){
            C[i][j] = 0;
            for (int k=0;k<N;k++){
                C[i][j]+=(A[i][k]*B[k][j]);
            }
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<P-1;j++){
            printf("%d ",C[i][j]);
        }
        printf("%d\n",C[i][P-1]);
    }
    return 0;
}