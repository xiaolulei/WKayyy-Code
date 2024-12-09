#include<stdio.h>
int main()
{
    char a[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for(int i=0;i<=9;i++){
        int temp=a[i];
        a[i]=a[19-i];
        int result=19-i;
        a[result]=temp;
    }
    printf("%s",a);
    return 0;
}