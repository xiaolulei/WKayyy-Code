#include<stdio.h>
#include<string.h>
int main(){
    char a[7];
    int sum1=1;
    char b[7];
    int sum2=1;
    scanf("%s",a);
    scanf("%s",b);
    int len1=strlen(a);
    int len2=strlen(b);
    for(int i=0;i<len1;i++){
        sum1*=a[i]-'A'+1;
    }
    for(int i=0;i<len2;i++){
        sum2*=b[i]-'A'+1;
    }
    if((sum1%47)==(sum2%47)){
        printf("GO");
    }
    else 
    printf("STAY");
    return 0;
}