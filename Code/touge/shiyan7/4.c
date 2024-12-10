#include<stdio.h>
int num[11][11];
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            scanf("%d",&num[i][j]);
        }
    }
    int sum1=0,sum2=0;
    for(int i=0;i<a;i++){
        for(int j=a-1;j>=i;j--){
            sum1+=num[i][j];
        }
    }
    for(int i=a-1;i>=0;i--){
        for(int j=a-1-(a-1-i);j>=0;j--){
            sum2+=num[i][j];
        }
    }
    printf("%d %d",sum1,sum2);
}