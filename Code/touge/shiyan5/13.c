#include<stdio.h>
int main(){
    int Y,M1,D1,M2,D2;
    scanf("%d%d%d%d%d",&Y,&M1,&D1,&M2,&D2);
    int flag=0;
    if(Y==1) {printf("0");
    return 0;
    }
    if(M1>M2){
        int temp1=M1;
        M1=M2;
        M2=temp1;
        int temp2=D1;
        D1=D2;
        D2=temp2;
        flag=1;
    } 
    int gap=0;
    if(M1==M2) gap=D2-D1;
    else{
        for(int i=M1+1;i<=M2-1;i++){
            if(i==2) continue;  
            if(M2-1<=7){
                if(i%2==0) gap+=30;
                else gap+=31;
            }
            if(M2-1>7){
                if(i<=7){
                    if(i%2==0) gap+=30;
                else gap+=31;
            }
                else{
                    if(i%2==0) gap+=31;
                    else gap+=30;
                }
            }        
        }
        if(M1<2&&M2>2){
                if(Y%4==0||Y%400==0) gap+=29;
                else gap+=28; 
            }
        gap+=D2;
        if(M1==2){
            if(Y%4==0||Y%400==0) gap=gap+(29-D1+1);
                else gap=gap+(28-D1+1); 
        }
        else{
            if(M1<=7){
                if(M1%2==0) gap=gap+(30-D1+1);
                else gap=gap+(31-D1+1);
            }
            if(M1>7){
                if(M1%2==0) gap=gap+(31-D1+1);
                    else gap=gap+(30-D1+1);
            }
        }
    }
    if(flag){
        printf("%d\n",1-gap);
        return 0;
    }
    printf("%d\n",gap-1);
    return 0;
}
/*
1-7/8  奇数为31天
3-7/8
2-7/8
1-12    前八个月奇数为31天 后几个月偶数为31天
2-12
3-12
*/