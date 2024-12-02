#include <stdio.h>
int hanoi(int num) {
	/**********Begin**********/
	if (num == 1) {
        return 1;  
    }
    return 2*hanoi(num - 1)+1;
    /**********End**********/
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", hanoi(n));
	return 0;
}
// 1
// 2
// 