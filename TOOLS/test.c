#include<stdio.h>
int main(){
    char a[5],b[5];
    int sum;
    scanf("%s",&a);
    getchar();
    scanf("%s",&b);
    sum=a-b;
    printf("%s%s\n",a,b);
    printf("%d",sum);
}