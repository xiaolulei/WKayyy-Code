#include<stdio.h>
#include<string.h>
int main(){
    int flag=1;
    int n=0,sum=0;
    char s[1000];
    scanf("%d",&n);
    scanf("%s",&s);
    for(int i=0;i<n;i++){
        if(s[i]=='V'&&s[i+1]=='K'){
            sum++;
            s[i]='X';
            s[i+1]='X';
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!='X' && s[i]==s[i+1]){
            sum++;
            break;
        }
    }
    printf("%d",sum);
    return 0;
}