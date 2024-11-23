#include<stdio.h>
#include<math.h>

//定义main函数
int main()
{
	//请在此添加您的代码
	/*****************Begin******************/
    double x[1000];
    x[1]=0.0;
    int i = 0;
    for(;;i++){
        x[i]=x[i+1];
        x[i+1]=cos(x[i]);
        printf("%lf %lf\n",x[i],x[i+1]);
        if(abs(x[i]-x[i+1])<1E-6) break;
    }
    printf("root=%f",x[i]);
    
    








    
	/***************** End ******************/
	return 0;
}
