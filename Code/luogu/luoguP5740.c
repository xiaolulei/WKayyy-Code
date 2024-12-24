#include<stdio.h>
int find_max(int all[]);
struct student{
    char name[10];
    int CHI,ENG,MATH;
}people[1001];
int N;
int main()
{
    int all[1001];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",people[i].name);
        scanf("%d%d%d",&people[i].CHI,&people[i].MATH,&people[i].ENG);
        all[i]=people[i].CHI+people[i].MATH+people[i].ENG;
    }
    int max=find_max(all);
    printf("%s %d %d %d",people[max].name,people[max].CHI,people[max].MATH,people[max].ENG);
    return 0;
}
int find_max(int all[]){
    int max=0;
    for(int i=1;i<N;i++){
        if(all[max]<all[i]){
            max=i;
        }
    }
    return max;
}