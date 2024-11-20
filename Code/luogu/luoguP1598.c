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
    int lena=strlen(a)-1;
    int lenb=strlen(b)-1;
    int lenc=strlen(c)-1;
    int lend=strlen(d)-1;
    int max=0;
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
    char text[100][100]={' '};
    for(int i=1;i<=26;i++)
    {
        if(character[max]<character[i]) max=i;
    }
    for(int i=1,p=1;i<=52;i+=2,p++)
    {
        for(int j=1;j<=character[p];j++)
        {
            text[i][j]='*';
        }
    }
    for(int i=1;i<=52;i++){
        for(int j=1;j<=max;j++){
            printf("%c",text[i][j]);
        }
        printf("\n");
    }
    return 0;
}