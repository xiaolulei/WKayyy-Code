#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s);
    int sum=0;
    int len = strlen(s);
    printf("%c",s[len]);
    for(int i=0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z')
		sum++;
		if(s[i]>='a'&&s[i]<='z')
		sum++;
		if(s[i]>='0'&&s[i]<='9')
		sum++;
        }
    printf("%d",sum);
    return 0;
    }
