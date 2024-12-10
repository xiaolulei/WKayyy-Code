#include<stdio.h>
int num[15][15];
int main()
{
    int N;
    scanf("%d",&N);
    int s=1;
    for(int i=0;i<N;i++){
        if((i+1)%2!=0){
            for(int j=0;j<N;j++){
                num[i][j]=s;
                s++;
            }
        }
        else{
            for(int j=N-1;j>=0;j--){
                num[i][j]=s;
                s++;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            printf("%03d ",num[i][j]);
        }
        printf("%03d",num[i][N-1]);
        printf("\n");
    }
    return 0;
}