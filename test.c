#include <stdio.h>
#include <string.h>
struct student {
    char name[20];
    int year;
    int grade;
};
int main() {
    struct student s[6];
    int n;
    char buffer[100];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%s %d %d", s[i].name, &s[i].year, &s[i].grade);
    }
    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", s[i].name, s[i].year, s[i].grade);
    }

    return 0;
}