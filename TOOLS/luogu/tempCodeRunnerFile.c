#include<stdio.h>
int main(){
    int flag=1;
    int n=0,sum=0;
    char s[1000];
    scanf("%d",&n);
    getchar();
    gets(s);
    if(n==2){
        if(s[0]=='V'&&s[1]=='V') {
            printf("1");
            return 0;
        }
            if(s[0]=='K'&&s[1]=='K') {
            printf("1");
            return 0;
        }
    }
    for(int i=0;i<=n;i++){
        if(s[i]=='V'&&s[i+1]=='K'){
            sum++;
        }
        if(n>1&&flag){
            if(s[i]=='K'&&s[i-1]=='K'&&s[i+1]=='K') {
                sum++;
                flag=0;
                continue;
                }
            if(s[i]=='V'&&s[i-1]=='V'&&s[i+1]=='V'){
                sum++;
                flag=0;
            }
        }
    }
    printf("%d",sum);
    printf("\n");
    return 0;
    }