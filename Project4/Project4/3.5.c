#include<stdio.h>
#define PI 3.14;
int main(void)
{
	/*********Begin*********/
	double r, h;
	double C1, Sb, r, Vb;
	scanf("%f%f", r, h);
	C1 = PI * 2 * r;
	Sb = 4 * PI * r * r;
	Vb = 4 / 3 * PI * r * r * r;
	printf("C1=%.2f\n%Sb=.2f\n%Vb=.2f", C1, Sb, Vb);
	/*********End**********/
	return 0;
}
