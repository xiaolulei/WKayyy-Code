#include<stdio.h>
#include<string.h>
char b[1000000];
int mian(){
    char a[20];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    int flag=-1;
    int sum=0,sum1=0;
    int len1=strlen(a);
    int len2=strlen(b);
    int i=1;
    int sum3[100];
    for(int i=0;i<=len2-2;){
        if(b[i]==a[0]){
            for(int j=1;j<=len2-2;){
                if(b[i]==a[j]) {
                j++;
                sum++;
                }
                else {
                    sum=0;
                    break;
                }
                if(sum==len1) sum1++;
        }
        
        
        
        
        printf("%d",sum1);
    return 0;
}