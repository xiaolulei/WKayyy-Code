#include<stdio.h>
#include<string.h>
int main()
{
    char a[110],b[110],c[110],d[110];
    int character[27]={0};//数据的初始化
    gets(a);
    gets(b);
    gets(c);
    gets(d);
    int lena=strlen(a);
    int lenb=strlen(b);
    int lenc=strlen(c);
    int lend=strlen(d);
    int max=1;
    for(int i=0;i<lena;i++)//循环条件的设置
    {
        character[a[i]-64]++;
    }
    for(int i=0;i<lenb;i++)
    {
        character[b[i]-64]++;
    }
    for(int i=0;i<lenc;i++)
    {
        character[c[i]-64]++;
    }
    for(int i=0;i<lend;i++)
    {
        character[d[i]-64]++;
    }
    char text[110][110];
    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            text[i][j]=' ';
        }
    }
    for(int i=1;i<=26;i++)
    {
        if(character[max]<character[i]) max=i;
    }
    for(int i=1;i<=26;i++){
        for(int j=1;j<=character[i];j++){
            text[i][j]='*';
        }
    }
    for(int i=character[max];i>=1;i--){
        for(int j=1;j<=26;j++){
            printf("%c",text[j][i]);
        }
        printf("\n");
    }
    return 0;
}

//THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.