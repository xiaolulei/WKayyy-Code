#include<stdio.h>
struct student
{
    char num[10];
    char name[15];
    int age;
    char sex;
    float score;
};
struct student s1,s2;
int main()
{
    struct student t={"1234567890","abcdefghijklmno",1,'m',100.0};
    printf("%s%s%d%c%f\n",t.num,t.name,t.age,t.sex,t.score);
    printf("%d",sizeof(struct student));
    printf("%d",sizeof(s1));
    return 0;
}