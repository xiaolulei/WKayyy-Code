#include<stdio.h>
#include<math.h>
	int main(void)
	{  
	  /*********Begin*********/
	  int a,n;
      int sum1=1.0,sum2=0.0;
      scanf("%d%d",&a,&n);
      n--;
      while(n>=0){
            sum1=1.0;
            if(n>=1){
            for(int i=0;i<n;i++){
              sum1*=10;
              sum1+=1;
            }
            }
            sum1*=a;
            sum2+=sum1;
            
            n--;
      }
  printf("%d\n",sum2);
	  /*********End**********/ 
       return 0;
	}
