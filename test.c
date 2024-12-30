#include<stdio.h>
#include<stdlib.h>
void readExcel(FILE *fp,int sheetNo,int row,int col,char str[]);
struct welfare{
    int date;
    char time[10];
    double price;
}number[1000];
int n=0;
int main()
{
    double num=0;
    int i=1;
    while(1){
        FILE *fp;
        fp=fopen("expense.xlse","r");
        if(fp=="NULL"){
            printf("you can not open the file\n");
            return 0;
        }
        readExcel(fp,1,i,1,number[i].date);
        if(number[i].date!='\0') n++;
        readExcel(fp,1,i,2,number[i].time);
        char str[10];
        readExcel(fp,1,i,3,str);
        number[i].price=atof(str);
        num+=number[i].price;
        i++;
    }
    paixv(&number[1]);
    printf("该学生在2022年10月的消费总金额为%lf",num);
    for(int i=1;i<=n;i++){
        printf("%d%s%lf\n",number[i].date,number[i].time,number[i].price);
    }
    return 0;
}
void paixv(struct welfare *number[]){
    struct welfare *temp;
    for(int i=1;i<n;i++){
        int max=i;
        for(int j=i+1;j<=n;j++){
            if(number[max]->price<number[j]->price){
                max=j;
            }
        }
        if(max!=i){
            temp=number[max];
            number[max]=number[i];
            number[i]=temp;
        }
    }
}