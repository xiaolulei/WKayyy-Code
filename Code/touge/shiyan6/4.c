#include <stdio.h>
long long hanoi(int num) {
	/**********Begin**********/
	if (num == 1) {
        return 2;  
    }
    return 3*hanoi(num - 1)+2;
    /**********End**********/
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", hanoi(n));
	}
	return 0;
}
// 3 26 10 59048 1 2