#include<stdio.h>
int main() {
	int a[100]={0}, sum1 = 0, b[100]={0}, sum2 = 0;
	while (sum1 == 0) {
		scanf("%d", a[sum1]);
		sum1++;
	}
	while (sum1 > 0) {
		b[sum2] = a[sum1] - a[sum1 - 1];
		sum2++;
	}
	for (int i = 0; i < sum2; i++) {
		printf("%d", b[i]);
	}
	return 0;
}