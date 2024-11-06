#include <stdio.h>
#define N 100
int main()
{
    int num,NUM,X=0;
    char ch1[N],ch2[N];
    printf("请输入:\n");
    scanf("%s",ch1);
    printf("位数:\n");
    scanf("%d",&num);
    if (num>=0)
    NUM=num%26;
    else
    NUM=-((-num)%26)+26;
    for (int i=0;ch1[i]!='\0';i++)
    {
        if (ch1[i]>='A'&&ch1[i]<='Z')
        {
            if (ch1[i]>'Z'-NUM)
            ch2[i]=ch1[i]+NUM-26;
            else
            ch2[i]=ch1[i]+NUM;
        }
        else if (ch1[i]>='a'&&ch1[i]<='z')
        {
            if (ch1[i]>'z'-NUM)
            ch2[i]=ch1[i]+NUM-26;
            else
            ch2[i]=ch1[i]+NUM;
        }
        else
        ch2[i]=ch1[i];
        X++;
    }
    if (num>=0)
    printf("加密:\n");
    else
    printf("解密:\n");
    for (int i=0;i<X+1;i++)
    printf("%c",ch2[i]);
    return 0;
}