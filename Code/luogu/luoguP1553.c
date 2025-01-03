#include<stdio.h>
int main()
{
    //小数，分数，百分数，整数。
    //整数反转是将所有数位对调；
    //小数反转是把整数部分的数反转，再将小数部分的数反转，不交换整数部分与小数部分；
    //分数反转是把分母的数反转，再把分子的数反转，不交换分子与分母；
    //百分数的分子一定是整数，百分数只改变数字部分。
    char in[100]={0};
    char out[100];
    scanf("%s",in);
    int end=-1, point=-1, flag=1; // 初始化 end 和 point
    // 整数为1，小数为2，分数为3，百分数为4；
    for(int i=0;i<100;i++){
        if(in[i]==0){ 
            end=i-1;
            break;
        }
        if(in[i]=='.') {
            point=i;
            flag=2;
        }
        else if(in[i]=='/') {
            point=i;
            flag=3;
        }
        else if(in[i]=='%'){
            end=i;
            flag=4;
            break;
        }
    }
    if(end==-1) {
        printf("%c",in[0]);
        return 0;
    }
    switch(flag){
        case 1:{
            for(int i=0,j=end;i<=end;i++,j--){
                out[j]=in[i];
            }
            int outposition=0;//去除零，即从有数的地方输出；
            int judge;
            for(int i=0;i<=end;i++){
                if(out[i]!='0') {
                    outposition=i; 
                    break;
                }
            }
            for(int i=outposition;i<=end;i++){
                printf("%c",out[i]);
            }
            return 0;
        }
        case 2:{
            int sum1=0,sum2=0;
            for(int i=0,j=point-1;i<=point-1;i++,j--){
                out[j]=in[i];
            }
            for(int i=point+1,j=end;i<=end;i++,j--){
                out[j]=in[i];
            }
            int outposition1,outposition2;
            for(int i=0;i<=point-1;i++){
                if(out[i]=='0'&&point-1==0){
                    outposition1=i;
                    break;
                }
                if(out[i]=='0') sum1++;
                if(out[i]!='0') {
                    outposition1=i;
                    break; 
                }
            }
            if(sum1==point) outposition1=point-1;
            for(int i=point+1;i<=end;i++){
                if(end==point+1&&out[point+1]=='0'){
                    outposition2=i;
                    break;
                } 
                if(out[i]=='0') sum2++;
                if(out[i]!='0'&&out[i]!=0) outposition2=i;
            }
            if(sum2==end-point) outposition2=point+1;
            for(int i=outposition1;i<=point-1;i++){
                printf("%c",out[i]);
            }
            printf(".");
            for(int i=point+1;i<=outposition2;i++){
                printf("%c",out[i]);
            }
            return 0;
        }
        case 3:{
            for(int i=0,j=point-1;i<=point-1;i++,j--){
                out[j]=in[i];
            }
            for(int i=point+1,j=end;i<=end;i++,j--){
                out[j]=in[i];
            }
            int outposition1,outposition2,sum=0;
            for(int i=0;i<=point-1;i++){
                if(out[i]=='0'&&point-1==0){
                    outposition1=i;
                    break;
                }
                if(out[i]=='0') sum++;
                if(out[i]!='0') {
                    outposition1=i;
                    break; 
                }
            }
            if(sum==point) outposition1=point-1;
            for(int i=point+1;i<=end;i++){
                if(out[i]!='0') {
                    outposition2=i; 
                    break;
                } 
            }
            for(int i=outposition1;i<=point-1;i++){
                printf("%c",out[i]);
            }
            printf("/");
            for(int i=outposition2;i<=end;i++){
                printf("%c",out[i]);
            }
            return 0;
        }
        case 4:{
            for(int i=0,j=end-1;i<end;i++,j--){
                out[j]=in[i];
            }
            int outposition = -1;
            for(int i=0;i<end;i++){
                if(out[i]!='0') {
                    outposition=i;
                    break;
                } 
            }
            if(outposition==-1) {
                printf("0%%");
            } else {
                for(int i=outposition;i<end;i++){
                    printf("%c",out[i]);
                }
                printf("%%");
            }
            return 0;
        }
    }
    return 0;
}