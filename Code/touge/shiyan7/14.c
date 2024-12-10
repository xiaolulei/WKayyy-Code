#include<stdio.h>
#include<string.h>
int count(char *str);
int main() {
    char a[101];
    scanf("%[^\n]",a);
    int result=count(a);
    printf("%d\n",result);
    return 0;
}
int count(char *str){
    int count=0;
    int flag=1;
    while(*str!='\0') {
        if ((*str>=33 &&*str<=126)&&flag) {
            count++;
            flag=0;
        }
        if(*str==' ') {
            flag=1;
        }
        str++;
    }
    return count;
}