#include<stdio.h>
#include<string.h>

int main()
{
    char coin1[1005],coin2[1005];
    scanf("%s",coin1);
    getchar();
    scanf("%s",coin2);
    int len=strlen(coin1);
    int sum=0;
    for(int i=0;i<len;i++){
        if(coin1[i]!=coin2[i]){
            coin1[i+1]=(coin1[i+1]=='*'?'o':'*');
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}