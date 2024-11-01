#include<stdio.h>
#include<math.h>
	int main(void)
	{  
	  /*********Begin*********/
	  float a,b,c;
      float x1,x2;
      float sum;
      printf("Please enter the coefficients a,b,c:\n");
      scanf("%f,%f,%f",&a,&b,&c);
      sum=b*b-4*a*c;
      if(sum<0) {
        printf("error!");
        return 0;
        }
      x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	  x2=(-b-sqrt(b*b-4*a*c))/(2*a);
      printf("x1=%.4f, x2=%.4f",x1,x2);
	  /*********End**********/ 
       return 0;
	}