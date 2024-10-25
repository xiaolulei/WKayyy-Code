#include<stdio.h>
#include<math.h>
	int main(void)
	{
	  /*********Begin*********/
	  float a,b,c,area,s,sum;
      scanf("%f%f%f"&a,&b,&c);
	  s=(a+b+c)/2;
      sum=s*(s-a)*(s-b)*(s-c);
      area=sqrt(sum);
      printf("%.3f",area);
	  /*********End**********/
       return 0;
	}
