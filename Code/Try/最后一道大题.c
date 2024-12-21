#include<stdio.h>

void xuanze_sort(struct students people[]);

struct students
{
    char name[20];
    int code;
    char machine[20];
    int data1;
    int data2;
};

int output[101];
int time_gap[101];

struct students people[101];
    FILE *a,*b;
int main()
{   
    a=fopen("test.txt","r");
    b=fopen("time_out_15.txt","w");
    for(int i=0;i<100;i++){
        char temp[200];
        fgets(temp,sizeof(temp),a);
        sscanf(temp,"%s %d %s %d %d",&people[i].name,&people[i].code,&people[i].machine,&people[i].data1,&people[i].data2);
    }
    fclose(a);
    xuanze_sort(people);
    timecaculate(people);
    for(int i=0;i<100;i++){
        printf("%s %d %s %d %d\n",people[i].name,people[i].code,people[i].machine,people[i].data1,people[i].data2);
    }
    return 0;
}
void xuanze_sort(struct students people[]){
    for(int i=0;i<99;i++){
        struct students temp;
        int min=i;
        for(int j=i+1;j<100;j++){
            if(people[min].code>people[j].code) min=j;
        }
        if(min!=i){
            temp=people[i];
            people[i]=people[min];
            people[min]=temp;
        }
    }
}

void timecaculate(struct students people[]){
    for(int i=0;i<100;i++){
        int temp1=people[i].data1;
        int temp2=people[i].data2;
        int temp11,temp12,temp13;
        int temp21,temp22,temp23;
        sscanf(temp1,"%d.%d.%d",&temp11,&temp12,&temp13);
        sscanf(temp2,"%d.%d.%d",&temp21,&temp22,&temp23);
        int gap;
        gap=time(temp11,temp12,temp13,temp21,temp22,temp23);
        if(gap>15){
            fprintf(b,"%s %d",people[i].name,gap);
        }
    }
}

int time(int temp11,int temp12,int temp13,int temp21,int temp22,int temp23){
    int gap=0;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(temp11!=temp21) 
    {
        for(int i=temp11+1;i<temp21;i++){
            if(runnian_panduan(i)){
                gap+=366;
            }
            else gap+=365;
        }
        for(int i=temp12+1;i<=12;i++){
            gap+=month[i];
        }
        for(int i=1;i<temp22;i++){
            gap+=month[i];
        }
        gap+=month[temp12]-temp13;
        gap+=month[temp22];
    }
    else{
    if(temp12==temp22){
        gap+=(temp23-temp13);
        }
    else{
        gap+=month[temp12]-temp13;
        for(int i=month+1;i<temp22;i++){
            gap+=month[i];
        }
        gap+=month[temp22];
        }
    }
    return gap;
}

int runnian_panduan(int year){
    if(year%400==0||(year%4==0&&year%100!=0)){
        return 1;
    }
    else return 0;
}

/*例2：某教学平台，会在后台记录学生登录学习系统的相关信息，期中包含最近两次的日期，信息保存在一个文本文件test.txt中，如：
张三 0017 term023 2024.10.9 2024.10.15
表示的信息分别是：姓名，学生编号，登录的机器号，日期1，日期2，数据项间用空格进行了区分。
现要求编写程序：
（1）读取文件中的内容并按学生编号的顺序打印输出所有学生信息。
（2）对学生信息进行处理，如发现学生最近两次登录时间间隔超过15天，则打印他的名单及两次登录间隔的天数。
假设 有100号学生 同时 这一百个学生的学号不相邻，即有一些学生没有录入  
*/

/*
结构体存储学生信息 
由于一百个学生学号不相邻，那就定义一个数组来存储学生的指针，并根据学好大小从小到大排序 达到顺序输出的作用
同时我们还要满足输出时间间隔超过15天的学生，要打印名单以及间隔的天数（这里假设我们输出到一个文件里）


main函数的作用：
读取文件中的内容，并把指针存入一个数组中，再用函数a来排序
向文件输出内容，将超过十五天的学生写到文件里
（1.试着计算超过的总天数。  2.试着将这些同学排序后输出）
*/