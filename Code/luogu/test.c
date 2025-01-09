#include<stdio.h>
#include<string.h>

int main()
{
    char a[505], b[505];
    int a1[505] = { 0 }, b1[505] = { 0 }, c[505] = { 0 };
    scanf("%s", a);
    scanf("%s", b);
    int lena = strlen(a);
    int lenb = strlen(b);
    for (int i = 0; i < lena; i++) {
        a1[lena - 1 - i] = a[i] - '0';
    }
    for (int i = 0; i < lenb; i++) {
        b1[lenb - 1 - i] = b[i] - '0';
    }
    int lenc;
    if (lena > lenb) {
        lenc = lena;
    }
    else {
        lenc = lenb;
    }
    lenc++;
    int sum, carry = 0;
    for (int i = 0; i < lenc; i++) {
        sum = a1[i] + b1[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        c[lenc++] = carry;
    }
    while (c[lenc - 1] == 0 && lenc > 1) {
        lenc--;
    }
    for (int i = lenc - 1; i >= 0; i--) {
        printf("%d", c[i]);
    }
    return 0;
}