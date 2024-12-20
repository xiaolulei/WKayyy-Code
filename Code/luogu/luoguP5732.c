#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int num[31][31];
    int status=1;
    int sum=1;
    for(int i=0;i<31;i++){
        for(int j=0;j<31;j++){
            num[i][j]=-1;
        }
    }
    int i=0,j=0;
    while(sum<=N*N){
        if(num[i][j]==-1){
            num[i][j]=sum++;
        }
        if(status==1){
            j++;
            if(j==N||num[i][j]!=-1){
                status=2;
                j--;
            }
        }
        else if(status==2){
            i++;
            if(i==N||num[i][j]!=-1){
                status=3;
                i--;
            }
        }
        else if(status==3){
            j--;
            if(j==-1||num[i][j]!=-1){
                status=4;
                j++;
            }
        }
        else if(status==4){
            i--;
            if(i==-1||num[i][j]!=-1){
                status=1;
                i++;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            printf("%3d",num[i][j]);
        }
        printf("%3d",num[i][N-1]);
        printf("\n");
    }
    return 0;
}
