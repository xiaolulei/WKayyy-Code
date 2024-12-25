#include<stdio.h>
#include<math.h>
int main()
{
    double s,v;
    scanf("%lf%lf",&s,&v);
    int min=ceil(s/v);
    int h=min/60;
    min%=60;
    int outh=7,outmin=50;
    outmin-=min;
    outh-=h;
    if(outmin<0){
        outmin+=60;
        outh-=1;
    }
    if(outh<0) outh+=24;
        printf("%02d:%02d\n",outh,outmin);
    return 0;
}