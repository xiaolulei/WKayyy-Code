#include<stdio.h>
#include<math.h>
double f(double x);
int main(){
    double wucha;
    scanf("%lf",&wucha);
    double fx;
    double a=0,b=2;
    double x=(a+b)/2;
    fx=f(x);
    double fa=f(a);
    if(fa*fx>0){
        a=x;
    }
    else b=x;
    while(fabs(fx)>=wucha){
        x=(a+b)/2;
        fx=f(x);
        fa=f(a);
        if(fa*fx>0){
        a=x;
    }
    else b=x;
    }
    printf("%.8lf",x);
    return 0;
}


double f(double x){
    double sum;
    sum=x*x*x*x*x-2*x*x*x*x+x*x-3;
    return sum;
}