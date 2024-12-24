#include<stdio.h>
#include<math.h>
#include<string.h>

struct student{
    char name[10];
    int CHI,ENG,MATH;
}people[1001];

int judge(int i,int j);
int N;
int all[1001];

int main()
{
    
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",people[i].name);
        scanf("%d%d%d",&people[i].CHI,&people[i].MATH,&people[i].ENG);
        all[i]=people[i].CHI+people[i].MATH+people[i].ENG;
    }
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(judge(i,j)){
                if(strcmp(people[i].name,people[j].name)>0){
                    printf("%s %s\n",people[j].name,people[i].name);
                }
                else{
                    printf("%s %s\n",people[i].name,people[j].name);
                }
            }
        }
    }
    return 0;
}

int judge(int i,int j){
    if(abs(all[i]-all[j])<=10){
        if(abs(people[i].CHI-people[j].CHI)>5||abs(people[i].ENG-people[j].ENG)>5||abs(people[i].MATH-people[j].MATH)>5)
        return 0;
        else return 1;
    }
    else return 0;
}