#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

/*
实训题1

使用结构体数组存放学生成绩信息，至少包含学号(整形)，语文、数学、英语、物理、化学这五门课程的百分制成绩。编写程序实现：
(1) 编写一个函数用来输入所有学生的信息(当输入的学号为0时，结束输入)；
(2)并将每个学生的全部数据保存到磁盘上的二进制文件StudentGrade.dat中。
提示：二进制文件创建语句pf=fopen("student.dat","wb");写二进制文件语句fwrite(&stu[i],sizeof(Student),1,fp);
*/

int flag = 0;

struct Score
{
    int StudentNum;
    float ChineseScore;
    float MathScore;
    float EnglishScore;
    float PhysicsScore;
    float ChemistryScore;
    float Score;
    float aveScore = (ChineseScore + MathScore + EnglishScore + PhysicsScore + ChemistryScore) / 5;
}StudentScore;

void quick_sort(Score q[],int l, int r);
void StudentSort();
void InitiateFile();
bool InputStudenInformation(FILE *fp);



void quick_sort(Score q[],int l,int r){
    if(l>=r) return;
    int i=l-1,j=r+1;
    float x=q[(l + r) >> 1].Score;
    while(i<j){
        do i++;while(q[i].Score<x);
        do j--;while(q[j].Score>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}


void StudentSort()
{
    //我们假设学生数据不超过100
    Score temp[100];
    FILE *fp;
    if((fp = fopen("StudentGrade.dat","r"))==NULL)
    {
        system("pls");
        printf("\nCan not open StudentGraade correctly!\n");
        system("pause");
        exit(0);
    }
    int pos = 0;
    while(fread(&temp[pos],sizeof(Score),1,fp)==1) pos++;
    fclose(fp);
    fp = fopen("StudentGrade.dat","w");
    if (fp == NULL) {
        cout << "Error opening file for writing!\n";
        exit(0);
    }

    quick_sort(temp,0,pos-1);

    for(int i = 0;i < pos; i++)
    {
        
        if(fwrite(&temp[i],sizeof(Score),1,fp)!=1)
        {
            printf("\nError writing to file! System Stop !\n");
            exit(0);
        }
    }
    fclose(fp);
}

void InitiateFile()
{
    char ch;
    FILE *fp;
    system("cls");//Do you want to initialize the file?
    printf("\n\n\tDo you want to initialize the file?");
    while (ch!='y' && ch!='Y' && ch!='n' && ch!='N'){
        printf("\n\n\t\tContinue? (y/n)  ");
        cin >> ch;
        if(ch == 'y' || ch == 'Y') break;
        else if (ch == 'n' || ch == 'N') return; 
    }
    char ch_again;
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nThe initialization of file will lose all data in data files! Are you sure?(y/n)");
    while (ch_again!='y' && ch_again!='Y' && ch_again!='n' && ch_again!='N'){
        cin >> ch_again;
        if(ch_again == 'y' || ch_again == 'Y') break;
        else if (ch_again == 'n' || ch_again == 'N') return; 
    }
    fp = fopen("StudentGrade.dat","w");
    printf("\n\nInitialization success!\n");
    fclose(fp);
    system("pause");
    system("cls");
}

void ErrorGradePrint()
{
    printf("--------------------------------------------------------------");
    printf("\n\n\t\tPlease Enter Correct Score!\n");
    printf("\n--------------------------------------------------------------");
}

bool InputStudenInformation(FILE *fp)
{
    Input_Start:
    Score x,t;
    system("cls");
    printf("\n\t\tStudents Information System\n");
    printf("\n================================================================\n");
    printf("\nPlease Input The Student's Information:  ");
    printf("\n-----------------------------------------");
    printf("\n\nPlease Input Student's num:  "); scanf("%d",&t.StudentNum); 
    if(t.StudentNum==0)
    {
            printf("--------------------------------------------------------------");
            printf("\n\n\t\tUser stops input!\n");
            printf("\n--------------------------------------------------------------");
            return false;
    }
    rewind(fp);
    bool exists = false;
    while (fread(&x, sizeof(Score), 1, fp) == 1) {
        if (x.StudentNum == t.StudentNum) {
            exists = true;
            break;
        }
    }
    
    if (exists) {
        char temp;
        system("cls");
        printf("================================================================");
        printf("\n\nThe student %d has existed !  Input next? (y/n) :", t.StudentNum);
        while (temp!='y' && temp!='Y' && temp!='n' && temp!='N') {
            cin >> temp;
            if (temp == 'y' || temp == 'Y') 
                return true;
            else if (temp == 'n' || temp == 'N')
            {
                system("cls");
                printf("--------------------------------------------------------------");
                printf("\n\n\t\tUser stops input!\n");
                printf("\n--------------------------------------------------------------");
                return false;
            }
                
        }
    }

    CHI:printf("\nPlease Input Student's Chinese Grade:  "); scanf("%f",&t.ChineseScore); 
    if(t.ChineseScore>100||t.ChineseScore<0)
    {
        ErrorGradePrint();
        goto CHI;
    }
    MATH:printf("\nPlease Input Student's Math Grade:  "); scanf("%f",&t.MathScore); 
    if(t.MathScore>100||t.MathScore<0)
    {
        ErrorGradePrint();
        goto MATH;
    }
    ENG:printf("\nPlease Input Student's English Grade:  "); scanf("%f",&t.EnglishScore); 
    if(t.EnglishScore>100||t.EnglishScore<0)
    {
        ErrorGradePrint();
        goto ENG;
    }
    PHY:printf("\nPlease Input Student's Physics Grade:  "); scanf("%f",&t.PhysicsScore); 
    if(t.PhysicsScore>100||t.PhysicsScore<0)
    {
        ErrorGradePrint();
        goto PHY;
    }
    CHE:printf("\nPlease Input Student's Chemistry Grade:  "); scanf("%f",&t.ChemistryScore); 
    if(t.ChemistryScore>100||t.ChemistryScore<0)
    {
        ErrorGradePrint();
        goto CHE;
    }
    t.Score = t.ChemistryScore + t.ChineseScore + t.EnglishScore + t.MathScore + t.PhysicsScore ;
    fseek(fp, 0, SEEK_END);
    fprintf(fp, "%d;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;\n",
        t.StudentNum,
        t.ChineseScore,
        t.MathScore,
        t.EnglishScore,
        t.PhysicsScore,
        t.ChemistryScore,
        t.Score);
    return true;
}

int main()
{
    InitiateFile();
    FILE *fp;
    if((fp = fopen("StudentGrade.dat","a+")) == NULL)
    {
        printf("--------------------------------------------------------------");
        printf("\n\n\tThe file is not initialized. Please initialize it first.\n");
        printf("\n--------------------------------------------------------------");
    }
    while(InputStudenInformation(fp));
    printf("\n");
    system("pause");
    system("cls");
    printf("-----------------------------------------------------------------");
    printf("\n\n\tDo you want to sort the data by grade values? : (y/n)");
    char command;
    do
    {
        command = getchar();
    }while(command != 'Y' && command != 'y' && command != 'N' && command !='n');
    if(command == 'Y' || command == 'y' ) 
    {
        StudentSort();
        printf("\n-----------------------------------------------------------------\n");
        printf("");
    }
    else if(command == 'N' || command == 'n' )
    {
        system("cls");
        printf("-----------------------------------------------------");
        printf("\n\nThe program closes cause the user stops input.\n\n");
        printf("-----------------------------------------------------");
    }
    return 0;
}