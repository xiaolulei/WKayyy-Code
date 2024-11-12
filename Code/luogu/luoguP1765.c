#include<stdio.h>
#include<string.h>
int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main(){
    char a[205];
    gets(a);
    int sum=0;
    int len = strlen(a);
    for(int j=0;j<len;j++){
        if(a[j]==' ') sum++;
        else if(a[j]>='a'&&a[j]<='z'){
            sum+=num[a[j]-'a'];
        }
    }
    printf("%d",sum);
    return 0;
}