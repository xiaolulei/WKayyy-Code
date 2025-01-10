#include<stdio.h>
#include<string.h>

int main()
{
    char s1[10001],s2[10001];
    int a[10001],b[10001],c[10001]={0};

    scanf("%s",s1);
    getchar();
    scanf("%s",s2);
    char str[10]={'0'};

    if(strcmp(str,s1)==0||strcmp(str,s2)==0){
        printf("0");
        return 0;
    }

    int len1=strlen(s1);
    int len2=strlen(s2);

    for(int i=0;i<len1;i++){
        a[len1-i]=s1[i]-'0';
    }
    for(int i=0;i<len2;i++){
        b[len2-i]=s2[i]-'0';
    }

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            c[i+j-1] += a[i]*b[j];
            if(c[i+j-1]>9){
            c[i+j] += c[i+j-1]/10;
            c[i+j-1]%=10;
            }
        }
    }

    int len3=len1+len2;
    while(c[len3]==0&&len3>0) len3--;
    for(int i=len3;i>0;i--){
        printf("%d",c[i]);
    }
    return 0;
}