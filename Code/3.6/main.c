#include<stdio.h>

int main() {
    char a[1000], b = 0;
    int sum = 0;
    printf("��������Ҫ���뼸���ַ�:");
    scanf("%d", &sum);

    // ������뻺�����еĻ��з�
    while (getchar() != '\n') continue;

    for (int i = 0; i < sum; i++) {
        scanf("%c", &a[i]);
        if (i > 0) {
            if (a[i] > b) {
                b = a[i];
            }
        } else {
            b = a[i]; // ��ʼ��bΪ��һ��������ַ�
        }
    }

    printf("%c\n", b);
    return 0;
}
