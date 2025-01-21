#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[500];
    scanf("%s",str);
    int len=strlen(str);
    printf("%c",str[0]);
    for(int i=1;i<len;i++){
        if(str[i]>='1'&&str[i]<='9'){
            for(int j=1;j<=str[i]-'0'-1;j++){
                printf("%c",str[i-1]);
            }
            continue;
        }
        printf("%c",str[i]);
    }
    return 0;
}