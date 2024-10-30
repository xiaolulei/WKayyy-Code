#include <stdio.h>
char str[1000];
int main() {
    int length = 0;
    fgets(str, 1000, stdin); 
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    printf("%d\n", length-1);
    return 0;
}