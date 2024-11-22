#include<stdio.h>
//编写题目要求的函数
/*********Begin*********/
double math(int n){
    double a=1.0,b=3.0;
    double s=1.0;
    double c=3;
    for(int i=1;i<=n;i++){
        printf("%f\n%f\n",a,b);
        double sum=a/b;
        s=s+a/b;
        a*=(i+1);
        c+=2;
        b=b*c;//1.5492063492
    }
    return s;
}
/*********End**********/ 
int main(void)
{  
    /*********Begin*********/
    int n;
    scanf("%d",&n);
    double s;
    s=math(n);
    //printf("%.10lf",s);
    /*********End**********/ 
    return 0;
}
