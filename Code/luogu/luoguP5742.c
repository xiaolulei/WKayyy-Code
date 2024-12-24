#include <stdio.h>

struct student {
    int code;
    int grade1;
    int grade2;
    int judge;
} people[1001];

void judge(struct student *people);

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d",&people[i].code,&people[i].grade1,&people[i].grade2);
        judge(&people[i]);
    }
    for (int i=0;i<N;i++) {
        if (people[i].judge==1) {
            printf("Excellent\n");
        }
        else {
            printf("Not excellent\n");
        }
    }
    return 0;
}

void judge(struct student *people) {
    if(people->grade1 + people->grade2>140) {
        if(people->grade1*7 + people->grade2*3>=800) {
            people->judge=1;
        }
        else{
            people->judge=0;
        }
    }
    else{
        people->judge=0;
    }
}