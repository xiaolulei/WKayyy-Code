#include<stdio.h>
#include<string.h>
int main(){
    char N[100];
    scanf("%s",N);
    int len=strlen(N);
    int flag=0;
    for(int i=len-1;i>=0;i--){
        if(N[i]>'0'){
           flag=1; 
        }
        if(flag){
            printf("%c",N[i]);
        }
    }
    return 0;
}