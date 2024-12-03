#include<stdio.h>
int main()
{
    int n;
    char str[200];//第二行输入数据
    char result[5][1000];
    scanf("%d",&n);
    getchar();
    gets(str);
    for(int i=1;i<=5;i++){
        for(int j=1;j<=400;j++){
            result[i][j]='.';
        }
    }
    for(int i=0,j=1;i<=n-1;i++,j+=4){
        if(str[i]=='0'){
            result[1][i]='*';
            result[1][i+1]='*';
            result[1][i+2]='*';
            for(int s=2;s<=4;s++){
                result[s][i]='*';
                result[s][i+2]='*';
            }
            

        }
    }
    return 0;
}