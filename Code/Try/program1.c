#include<stdio.h>
#include<string.h>
int main()
{
    char in[90],check[10];
    gets(in);
    if(in=="\n"){
        printf("��������ȷ���ַ���");
        return 0;
    }
    if(check=="\n"){
        printf("��������ȷ���ַ���");
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
    printf("�ڶ���������ַ����ڵ�һ��������ַ����г��ֵĴ���Ϊ��%d",count);
    return 0;
}