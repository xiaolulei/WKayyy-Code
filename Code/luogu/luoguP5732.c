#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num[20][20]={
        {1},
        {1,1}
    };
    for(int i=2;i<n;i++){
        num[i][0]=1;
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<n;j++){
            num[i][j]=num[i-1][j]+num[i-1][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j<n)
            printf("%d ",num[i][j]);
            else
            printf("%d",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}