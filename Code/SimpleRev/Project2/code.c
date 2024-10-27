#include<stdio.h>
int main() {
	int i;
	char key[] = "adsfkndcls";
	char text[] = "killshadow";
	int v3 = 10, v5 = 10;
	for (int i = 0; i < v5; i++) {
		for (int j = 0; i < 123; j++) {
			if ((j < 'A' || j>'Z') || (j < 'z' && j>'a')) {
				continue;
			}
			if ((j-39-key[v3%v5]+97)%26+97==text[i])
			{
				printf("%c", j);
				v3++;
				break;
			}
		}
	}
	return 0;
}
