#include<stdio.h>
int main()
{

    
    int n;
    char str[200];//第二行输入数据
    char result[5][500];
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
            result[1][i]='X';result[1][i+1]='X';result[1][i+2]='X';
            for(int s=2;s<=4;s++){
                result[s][i]='X';
                result[s][i+2]='X';
            }
            result[5][i]='X';result[5][i+1]='X';result[5][i+2]='X';
        }
        if(str[i]=='1'){
            for(int s=1;s<=5;s++){
                result[s][i+2]='X';
            }
        }
        if(str[i]=='2'){
            result[1][i]='X';result[1][i+1]='X';result[1][i+2]='X';
            result[2][i+2]='X';
            result[3][i]='X';result[3][i+1]='X';result[3][i+2]='X';
            result[4][i]='X';
            result[5][i]='X';result[5][i+1]='X';result[5][i+2]='X';
        }
        if(str[i]=='3'){
            result[1][i]='X';result[1][i+1]='X';result[1][i+2]='X';
            result[2][i+2]='X';
            result[3][i]='X';result[3][i+1]='X';result[3][i+2]='X';
            result[4][i+2]='X';
            result[5][i]='X';result[5][i+1]='X';result[5][i+2]='X';
        }
        if(str[i]=='4'){
            result[1][i]='X';result[1][i+2]='X';
            result[2][i]='X';result[2][i+2]='X';
            result[3][i]='X';result[3][i+1]='X';result[3][i+2]='X';
            result[4][i+2]='X';
            result[5][i+2]='X';
        }
        if(str[i]=='5'){
            result[1][i]='X';result[1][i+1]='X';result[1][i+2]='X';
            result[2][i]='X';
            result[3][i]='X';result[3][i+1]='X';result[3][i+2]='X';
            result[4][i+2]='X';
            result[5][i]='X';result[5][i+1]='X';result[5][i+2]='X';
        }
        if(str[i]=='6'){
            result[1][i]='X';result[1][i+1]='X';result[1][i+2]='X';
            result[2][i]='X';
            result[3][i]='X';result[3][i+1]='X';result[3][i+2]='X';
            result[4][i]='X';result[4][i+2]='X';
            result[5][i]='X';result[5][i+1]='X';result[5][i+2]='X';
        }
        if(str[i]=='7'){
            result[1][i]='X';result[1][i+1]='X';result[1][i+2]='X';
            result[2][i+2]='X';
            result[3][i+2]='X';
            result[4][i+2]='X';
            result[5][i+2]='X';
        }
        if(str[i]=='8'){
            result[1][i]='X';result[1][i+1]='X';result[1][i+2]='X';
            result[2][i]='X';result[2][i+2]='X';
            result[3][i]='X';result[3][i+1]='X';result[3][i+2]='X';
            result[4][i]='X';result[4][i+2]='X';
            result[5][i]='X';result[5][i+1]='X';result[5][i+2]='X';
        }
        if(str[i]=='9'){
            result[1][i]='X';result[1][i+1]='X';result[1][i+2]='X';
            result[2][i]='X';result[2][i+2]='X';
            result[3][i]='X';result[3][i+1]='X';result[3][i+2]='X';
            result[4][i+2]='X';
            result[5][i]='X';result[5][i+1]='X';result[5][i+2]='X';
        }
    }
    for(int i=5;i>=1;i--){
        for(int j=1;j<=4*n;j++){
            printf("%c",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}