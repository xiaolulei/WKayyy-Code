/*----------------------------------------
功能：计算并输出high以内最大的10个素数之和。
要求：只能修改错误区域中的错误代码。
      不能改动区域以外的程序。
----------------------------------------*/
#include <stdio.h>
#include<math.h>

int main()
{
	int sum=0,n=0,j,yes,high;
	//--------------错误区域开始------------------	
	scanf("%d",&high);
	while((high>=2)&&(n<10)) 
	{	
        yes=1;
		for(j=2;j<=sqrt(high);j++)
        
			if(high%j==0)
			{	
				yes=0; 
				continue;
			}
		if(yes)
		{	
			sum+=high;
			n++;
		}
		high--;
	
	}
	printf("sum=%d\n",sum);	
	//-----------错误区域结束---------------------
	return 0;
}
