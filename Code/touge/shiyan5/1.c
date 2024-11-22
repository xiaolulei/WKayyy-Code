#include <stdio.h>
int is_triangle(int, int, int);
int main() {
	int n, a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	n = is_triangle(a, b, c);
	switch (n) {
	case 0:
		printf("regular triangle!");
		break;
	case 1:
		printf("equilateral triangle!");
		break;
	case 2:
		printf("isosceles triangle!");
		break;
	case 3:
		printf("not a triangle!");
		break;

	}

}
int is_triangle(int a, int b, int c) {
	/**********Begin**********/
    if((a==b&&a!=c&&a+b>c)||(b==c&&a!=b)||(a==c&&b!=c))
    return 2;
    if(a==b&&b==c)
    return 1;
    if((a+b<=c)||(a+c<=b)||(b+c<=a))
    return 3;
    else return 0;
	/**********End**********/
}