#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int year,month,day;
    year=a/10000;
    month=(a/100)%100;
    day=a%100;
    int flag=1;
    if(month<0||month>12) flag=0;
    if(day<0||day>31) flag=0;
    if(month==2){
        if(year%4==0||year%400==0){
            if(day<0||day>29) flag=0;
        }
        else{
            if(day<0||day>28) flag=0;
        }
    }
    char str[10];
    if(flag){
        sprintf(str,"%d",a);
        for(int i=7,j=0;i>=4;i--,j++){
            if(str[i]==str[j]) continue;
            else{
                printf("NO");
                return 0;
            }
        }
        printf("YES");
    }
    else printf("NO");
    return 0;
}