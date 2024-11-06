#include <stdio.h>
int main() { 
    int a = 1,b = 1;
    double sum1=1,sum2=1;
    double s=0;
    int n=1;
    while(n<=10){
        sum1=a;
        sum2=b;
        if(n>=2) a+=1;
        b+=2;
        n++;
        s+= (double)sum1/sum2;
    }
       printf("%.3lf",s); 
       return 0;
}   
// s=1+1/3+2/5+………………+n-1/2n-1   当n=10时，s=1.571;