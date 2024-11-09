/*------------------------------------------------
功能：计算多项式之和
要求：请在数字标识的填空位置,补充程序。
      不能改动其他地方的程序
-------------------------------------------------*/
#include<stdio.h>
#include<math.h>

int main()
{
	double x,f,t;
	int n;
	scanf("%lf",&x);
    f=1.0+x;
    t=x;
    n=1;
    do{
		n++;
        t*=(x/n);
        f+=t;
	}while(t>=0.000001);
    printf("The result is :f=%-12.6f\n",f);
	return 0;
}