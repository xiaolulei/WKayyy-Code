#include<stdio.h>
char s[260];
int num[100];
int main(){
    scanf("%s",s);
    for(int i=0;s[i];i+=5){
        if((s[i+3]<='9'&&s[i+3]>='0')){
            num[s[i]]=s[i+3];
        }
        else num[s[i]]=num[s[i+3]];
    }
    if(num['a']!=0) num['a']-=48;
    if(num['b']!=0) num['b']-=48;
    if(num['c']!=0) num['c']-=48;
    printf("%d %d %d",num['a'],num['b'],num['c']);
    return 0;
}