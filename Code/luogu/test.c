#include<stdio.h>
int main()
{
    int a[10][10]={0};
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}