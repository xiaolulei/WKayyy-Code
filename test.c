#include <stdio.h>
#include <string.h>

int main() {
    int v4[] = {42, 70, 39, 34, 78, 44, 34, 40, 73, 63, 43, 64};
    int v4_len = sizeof(v4) / sizeof(v4[0]);
   char string[] = "]|[zyxwvutsrqponmlkjihgfedcba`_^]\\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)("
                    "'"
                    "&%$#!";
    char flag[13] = {0}; // 假设flag的长度不会超过12个字符
    int flag_len = 0;

    for (int i = 0; i < v4_len; i++) {
        for (int j = 1; j < strlen(string); j++) {
            if (v4[i] == string[j]) {
                flag[flag_len++] = j + 1; // 将索引+1转换为字符
                break; // 找到匹配项后跳出内层循环
            }
        }
    }

    printf("flag{");
    for (int i = 0; i < flag_len; i++) {
        printf("%c", flag[i]);
    }
    printf("}");

    return 0;
}