#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
	  double sum=0;
      double fenshu;
      double fenmu=1;
      int flag;
      for(int i=1;i<=100;i++){
          if(i%2==0)  flag = 1;
          else  flag = -1;
	      fenshu=flag*(1/fenmu);
          fenmu++;
          sum+=fenshu;
      }
      sum=sum*(-1);
      printf("%.3f",sum);
	  /*********End**********/ 
       return 0;
	}
