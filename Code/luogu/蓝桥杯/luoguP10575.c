#include<stdio.h>
int judge_runnian(int y);
int main()
{
    int year=2024;
    int remainder=judge_runnian(2024)%7;
    while(remainder!=0) {
        year++;
        if(judge_runnian(year)) {
            remainder=(remainder+2)%7;
        }else{
            remainder=(remainder+1)%7;
        }
    }
    printf("%d\n",year);
    return 0;
}

int judge_runnian(int y){
    if((y%4==0&&y%100!=0)||y%400==0){
        return 366;
    }
    else return 365;
}
