#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
	  char a[100];
      gets(a);
      int sum1=0,sum2=0,sum3=0,sum4=0;
	  for(int i=0;a[i];i++){
          if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z') sum1++;
          else if(a[i]>='0'&&a[i]<='9') sum2++;
          else if(a[i]==' ') sum3++;
          else sum4++;
      }
      printf("%d %d %d %d",sum1,sum2,sum3,sum4);
	  /*********End**********/ 
       return 0;
	}
