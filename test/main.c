#include<stdio.h>
	int main(void)
	{
	  /*********Begin*********/
	  float a;
	  scanf("%f",&a);
      if(a<0||a>100){
          printf("Score is error!");

      }
      if(a>=90){
          printf("A");
      }
      else if(a>=80){
          printf("B");
      }
      else if(a>=70){
          printf("C");
      }
      else if(a>=60){
          printf("D");
      }
      else {
          printf("E");
      }
	  /*********End**********/
       return 0;
	}
