#include <stdio.h>
#include <string.h>
int main() {
    int v4[] = {42,70,39,34,78,44,34,40,73,63,43,64};
    char string[] = {"~}|{zyxwvutsrqponmlkjihgfedcba`_^]\\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$#!"};
    char flag[100] = "";
    int i, j;
    for (i=0;i<sizeof(v4)/sizeof(v4[0]);i++) {
        for (j=0;j<strlen(string);j++) {
            if(v4[i]==(int)string[j]){
                flag[strlen(flag)]=(char)(j+1);
            }
        }
    }
    printf("flag{%s}\n",flag);
    return 0;
}