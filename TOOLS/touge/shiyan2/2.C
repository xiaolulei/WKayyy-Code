#include<stdio.h>
#include<math.h>
	int main(void)
	{  
	  /*********Begin*********/
	  int diqu;
      float zhongliang;
      float price=0.00;
      int a=1;
      scanf("%d,%f",&diqu,&zhongliang);
      if(diqu==0){
        if(zhongliang<1) price=10;
        else{
            if(fmod(zhongliang,1)==0){
                price=(zhongliang-1)*3+10;
            }
            else{
                zhongliang=ceil(zhongliang);
                price=(zhongliang-1)*3+10;
            }
        }
      }
      else if(diqu==1){
        if(zhongliang<1) price=10;
        else{
            if(fmod(zhongliang,1)==0){
                price=(zhongliang-1)*4+10;
            }
            else{
                zhongliang=ceil(zhongliang);
                price=(zhongliang-1)*4+10;
            }
        }
      }
      else if(diqu==2){
        if(zhongliang<1) price=15;
        else{
            if(fmod(zhongliang,1)==0){
                price=(zhongliang-1)*5+15;
            }
            else{
                zhongliang=ceil(zhongliang);
                price=(zhongliang-1)*5+15;
            }
        }
      }
      else if(diqu==3){
        if(zhongliang<1) price=15;
        else{
            if(fmod(zhongliang,1)==0){
                price=(zhongliang-1)*6.5+15;
            }
            else{
                zhongliang=ceil(zhongliang);
                price=(zhongliang-1)*6.5+15;
            }
        }
      }
      else if(diqu==4){
        if(zhongliang<1) price=15;
        else{
            if(fmod(zhongliang,1)==0){
                price=(zhongliang-1)*10+15;
            }
            else{
                zhongliang=ceil(zhongliang);
                price=(zhongliang-1)*10+15;
            }
        }
      }
      else{
        printf("Error in Area\n");
      }
      printf("Price: %.2f\n",price);
	  /*********End**********/ 
       return 0;
	}