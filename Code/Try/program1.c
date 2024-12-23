#include<stdio.h>
#include<string.h>
int main()
{
    char in[90],check[10];
    gets(in);
    if(in=="\n"){
        printf("请输入正确的字符串");
        return 0;
    }
    if(check=="\n"){
        printf("请输入正确的字符串");
        return 0;
    }
    int len1,len2;
    len1=strlen(in);
    len2=strlen(check);
    int count=0;
    for(int i=0;i<len1-len2;i++){
        int flag=0;
        if(in[i]==check[0]){
            for(int j=1;j<len2;j++){
                if(in[i+j]!=check[j]){
                    flag=0;
                    break;
                }
                else{
                    flag=1;
                }
            }
            if(flag){
                count++;
            }
        }
    }
    printf("第二行输入的字符串在第一行输入的字符串中出现的次数为：%d",count);
    return 0;
}