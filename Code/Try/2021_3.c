#include<stdio.h>
int fun(int a[][3]) {
 int i,s=0;
 for (i=0; i<3; i++) {
 s+=a[i][i];
 printf("s=%d\n",s);
 }
 return (s);
}
int main(){
 int sum,a[3][3]={2,1,1,9,8,5,3,4,6};
 sum=fun(a);
 printf("Sum=%d",sum);
 return 0;
}

