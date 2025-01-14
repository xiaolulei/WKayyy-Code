#include<stdio.h>

int main()
{
    int write_day=0;
    int num[10]={13,1,2,3,5,4,4,2,2,2};
    for(int i=2000;i<=2023;i++){//计算2024年之前
        int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int y1=i%10,y2=i/10%10,y3=i/100%10,y4=i/1000;
        if(i%400==0||(i%4==0&&i%100!=0)){
            day[2]+=1;
        }
        for(int j=1;j<=12;j++){
            for(int z=1;z<=day[j];z++){
                int all=num[y1]+num[y2]+num[y3]+num[y4]+num[j%10]+num[j/10]+num[z%10]+num[z/10];
                if(all>50){
                    write_day++;
                }
            }
        }
    }
    for(int i=1;i<4;i++){//计算2024年前三个月;
        int day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
        for(int j=1;j<=day[i];j++){
            int all=num[2]+num[0]+num[2]+num[4]+num[i]+num[j%10]+num[j/10]+num[0];
            if(all>50){
                write_day++;
            }
        }
    }
    for(int i=1;i<=13;i++){
        int all=num[2]+num[0]+num[2]+num[4]+num[0]+num[4]+num[i%10]+num[i/10];
        if(all>50) write_day++;
    }
    printf("%d",write_day);
    return 0;
}

