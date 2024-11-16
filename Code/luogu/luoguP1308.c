#include<stdio.h>
#include<string.h>
char b[1000000];
int main(){
    char a[20];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    int sum=0,sum1=0;
    int len1=strlen(a);
    int len2=strlen(b);
    for(int i=0;i<=len2-2;){
        if(b[i]==a[0]){
            for(int j=1;j<=len1-2;){
                if(b[i]==a[j]||b[i]==a[j]+32||b[i]==a[j]-32){
                    j++;
                    i++;
                    sum++;
                    if(sum==len1) break;
                }
                else {
                    sum=0;
                    break;
                }
            }
            if(sum==len1) sum1++;
        }
    }
    printf("%d",sum1);
    return 0;
}