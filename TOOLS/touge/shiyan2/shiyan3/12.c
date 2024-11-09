#include <stdio.h>
#include <string.h>
int main() {
    char a[1000];
    int flag;
    while (scanf("%s",a) == 1) {
        flag = 1; 
        int len = strlen(a);

        for (int i = 0; i < len / 2 ; i++) {
            if (a[i] != a[len-i-1]) {
                flag = 0;
                break; 
            }
        }
        if (flag) {
            printf("YES\n"); 
        }
        else printf("NO\n");
    }
    return 0;
}