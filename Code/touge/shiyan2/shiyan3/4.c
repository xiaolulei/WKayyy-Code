#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
      int n,sum=0;
      int temp=1;
      scanf("%d",&n);
	  if(n<0) {
          printf("0");
          return 0;
      }
     
          for(int i=n;i>0;i--){
              for(int j=i;j>0;j--){
                  temp*=j;
              }
              sum+=temp;
              temp=1;
          }
      printf("%d",sum);
	  /*********End**********/ 
       return 0;
	}
