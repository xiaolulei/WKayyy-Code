#include<stdio.h>
#include<stdlib.h>

//假定文件的输入是两个数据之间有一个空格

struct student{
    char name[20];
    int code;
    float math;
    float eng;
    float C;
    float all_score;
    int rank;
} Student[31];

int compare_by_all_score(const void *a,const void *b){
    struct student *studenta=(struct student *)a;
    struct student *studentb=(struct student *)b;
    if(studenta->all_score < studentb->all_score){
        return 1;
    }
    else if(studenta->all_score > studentb->all_score){
        return -1;
    }
    return 0;
}

int compare_by_Code(const void *a,const void *b){
    struct student *studenta=(struct student *)a;
    struct student *studentb=(struct student *)b;
    if(studenta->code < studentb->code){
        return -1;
    }
    else if(studenta->code > studentb->code) return 1;
}

int main(){
    FILE *input,*output1,*output2;
    input=fopen("D:\\score.txt","r");
    if(input==NULL){
        printf("无法打开文件,请检查文件是否存在,当前程序已退出");
    }
    for(int i=1;i<=30;i++){
        fscanf(input,"%s",&Student[i].name);
        fscanf(input,"%d",&Student[i].code);
        fscanf(input,"%f",&Student[i].math);
        fscanf(input,"%f",&Student[i].eng);
        fscanf(input,"%f",&Student[i].C);
        Student[i].all_score=Student[i].math+Student[i].eng+Student[i].C;
    }
    fclose(input);
    qsort(Student+1,30,sizeof(struct student),compare_by_all_score);
    Student[1].rank=1;
    for(int i=2;i<=30;i++){
        if(Student[i].all_score==Student[i-1].all_score){
            Student[i].rank=Student[i-1].rank;
        }
        else Student[i].rank=i;
    }
    output1=fopen("D:\\ScoreRanking.rec","w");
    if(output1==NULL){
        printf("无法正常生成文件,当前程序已退出");
        return 0;
    }
    fprintf(output1,"按总成绩排序的成绩单\n姓名 学号 数学 英语 C语言 总分\n");
    for(int i=1;i<=30;i++){
        fwrite(&Student[i],sizeof(struct student),1,output1);
        fprintf(output2,"\n");
    }
    fclose(output1);
    qsort(Student+1,30,sizeof(struct student),compare_by_Code);
    output2=fopen("D:\\newscore.rec","w");
    if(output2==NULL){
        printf("无法正常生成文件,当前程序已退出");
        return 0;
    }
    fprintf(output1,"按学号排序的成绩单\n姓名 学号 数学 英语 C语言 总分\n");
    for(int i=1;i<=30;i++){
        fwrite(&Student[i],sizeof(struct student),1,output2);
        fprintf(output2,"\n");
    }
    fclose(output2);
    return 0;
}