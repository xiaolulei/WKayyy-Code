#include<stdio.h>
#include<string.h>
int main()
{
    char a[51];
    scanf("%s",a);
    int len=0;
    len=strlen(a);
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            printf("%c",a[j]);
        }
        printf("\n");
    }
    return 0;
}