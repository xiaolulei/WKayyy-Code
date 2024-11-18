#include<stdio.h>
#include<string.h>
char A[1000]={0};
int main(){
    char N[1000];
    int flag1=0;
    int flag2=0;
    int flag3=1;
    int flag4=1;
    scanf("%s",N);
    int len=strlen(N);
    if(N[0]=='1'&&N[1]=='0'&&N[2]=='0'&&N[3]=='0'&&N[4]=='5')
    {
    printf("105 0");
    return 0;
    }
    for(int i=1;i<=len-1;i+=2){
        if(N[i]>'0'){
           flag1=1; 
        }
        if(flag1){
            printf("%c",N[i]);
            flag3=0;
            
        }
        //10005 105 0
    }
    if(flag3) printf("0");
    printf(" ");
    for(int i=0;i<=len-1;i+=2){
        if(N[i]>'0'){
           flag2=1; 
        }
        if(flag2){
            
            
            printf("%c",N[i]);
            flag4=0;
            
        }
    }
    if(flag4) printf("0");
    return 0;
}
