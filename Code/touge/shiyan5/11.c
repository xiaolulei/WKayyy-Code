#include<stdio.h>
int main(){
    int flag=1;
    int year,month,day;
    scanf("%d%d%d",&year,&month,&day);
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
    if(flag) printf("YES");
    else printf("NO");
    return 0;
}