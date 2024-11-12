#include<stdio.h>
#include<math.h>

//定义main函数
int main()
{
	//请在此添加您的代码
	/*****************Begin******************/
    double x1=0.0,x0=0.5;
    while((x0-x1)>=1E-6||(x1-x0)>=1E-6){    
        x0=x1;
        x1=cos(x0);
    }
    printf("root=%lf",x0);
	/***************** End ******************/
	return 0;
}
