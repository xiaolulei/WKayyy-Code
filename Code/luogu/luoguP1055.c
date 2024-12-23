#include<stdio.h>
int main()
{
    char ISBN[13];
    gets(ISBN);
    int num[10];
    num[0]=ISBN[0]-'0';
    for(int i=2;i<=4;i++){
        num[i-1]=ISBN[i]-'0';
    }
    for(int i=6;i<=11;i++){
        num[i-2]=ISBN[i]-'0';
    }
    num[9]=ISBN[12]-'0';
    int sum=0,flag=0;
    for(int i=1,j=0;i<=9;i++,j++){
        sum+=i*num[j];
    }
    sum=sum%11;
    if(sum==num[9]||(sum==10&&num[9]=='X'-'0')){
        flag=1;
    }
    if(flag){
        printf("Right");
    }
    else{
        if(sum==10){
            ISBN[12]='X';
        }
        else{
            ISBN[12]=sum+'0';
        }
        for(int i=0;i<13;i++){
            printf("%c",ISBN[i]);
        }
    }
    return 0;
}