    #include<stdio.h>
    #define M 50
    #define R 0.005
    int main(){
        int i;
        float sum1=0,sum2=0;
        for(i=1;i<=12;i++){
            sum1=sum1+M;
            sum2=sum2+(sum1=M*R);
        }
        printf("sum1=%.2f,sum2=%.2f,sum1+sum2=%.2f",sum1,sum2,sum1+sum2);
        return 0;
    }