#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c;
    float A,S;
    scanf("%f%f%f",&a,&b,&c);
    S=(a+b+c)/2;
    A=sqrt(S*(S-a)*(S-b)*(S-c));
    printf("%f",A);
    return 0;
}