#include<stdio.h>
int main(){
    int maxn=0,minn=0;
    char a[101];
    gets(a);
    int len = sizeof(a) / sizeof(a[0]);
    int b[len];
    int sum=0;
    for(int i=0;a[i];i++){
        for(int j=len;j>i;j++){
            sum++;
            if(a[i]==a[j]) b[sum]++;
        }
    }
    
    return 0;
}