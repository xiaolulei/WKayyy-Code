#include<stdio.h>
int main()
{
    int y;
    scanf("%d",&y);
    char str1[11][5] = {"geng", "xin", "ren", "gui", "jia", "yi", "bing", "ding", "wu", "ji"};
    char str2[13][5] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
    int temp,temp1,temp2;
    
    if(y>=1900){
        temp=(y-1900)%60;
        temp1=temp%10;
        temp2=temp%12;
    }
    else{
        temp=(1900-y)%60;
        temp1=10-temp%10;
        temp2=12-temp%12;
    }
    
    printf("%s%s\n",str1[temp1],str2[temp2]);
    return 0;
}