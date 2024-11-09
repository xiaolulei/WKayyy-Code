#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
	  int num=0,sum=1,temp=0;
      scanf("%d",&num);
      while(num!=0){
          temp=num%10;
          sum*=temp;
          num/=10;
      }
      printf("%d",sum);
	  /*********End**********/ 
       return 0;
	}
