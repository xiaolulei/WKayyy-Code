#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Score 
{
    int StudentNum;
    float ChineseScore;
    float MathScore;
    float EnglishScore;
    float PhysicsScore;
    float ChemistryScore;
    float TotalScore;
    float AveScore;
};

void clearInputBuffer() 
{
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
}

bool initFile() 
{
    char ch;
    system("cls");
    printf("\n\tInitialize student grade file? (Initialization will clear all data)\n");
    printf("\tPlease choose (y/n):  ");
    cin>>ch;
    if(ch!='y'&&ch!='Y') return true;

    printf("\n\tConfirm to clear all data? (y/n):  ");
    cin>>ch;
    if(ch!='y'&&ch!='Y') return true;

    FILE* fp=fopen("StudentGrade.dat","wb");
    if(!fp) 
    {
        printf("\n\tFile initialization failed!\n");
        return false;
    }
    fclose(fp);
    printf("\n\tFile initialization successful!\n");
    system("pause");
    system("cls");
    return true;
}

float calculateAverage(const Score& s) 
{
    return (s.ChineseScore+s.MathScore+s.EnglishScore+s.PhysicsScore+s.ChemistryScore)/5.0f;
}

bool saveStudentToFile(const Score& s) 
{
    FILE* fp=fopen("StudentGrade.dat","ab");
    if(!fp) 
    {
        printf("\n\tFile opening failed!\n");
        return false;
    }
    bool success=(fwrite(&s,sizeof(Score),1,fp)==1);
    fclose(fp);
    return success;
}

int loadStudents(Score students[],int maxSize) 
{
    FILE* fp=fopen("StudentGrade.dat","rb");
    if(!fp) return 0;

    int count=0;
    while(count<maxSize&&fread(&students[count],sizeof(Score),1,fp)==1) 
    {
        students[count].AveScore=calculateAverage(students[count]);
        count++;
    }
    fclose(fp);
    return count;
}

void quick_sort_total(Score q[],int l,int r) 
{
    if(l>=r) return;
    int i=l-1,j=r+1;
    float pivot=q[(l+r)/2].TotalScore;
    while(i<j) 
    {
        do i++; while(q[i].TotalScore<pivot);
        do j--; while(q[j].TotalScore>pivot);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort_total(q,l,j);
    quick_sort_total(q,j+1,r);
}

void quick_sort_average(Score q[],int l,int r) 
{
    if(l>=r) return;
    int i=l-1,j=r+1;
    float pivot=q[(l+r)/2].AveScore;
    while(i<j) 
    {
        do i++; while(q[i].AveScore>pivot);
        do j--; while(q[j].AveScore<pivot);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort_average(q,l,j);
    quick_sort_average(q,j+1,r);
}

void sortByTotalScore() 
{
    Score students[100];
    int count=loadStudents(students,100);
    if(count==0) 
    {
        printf("\n\tNo student data to sort!\n");
        return;
    }

    quick_sort_total(students,0,count-1);
    FILE* fp=fopen("StudentGrade.dat","wb");
    if(!fp) 
    {
        printf("\n\tFile opening failed, sorting failed!\n");
        return;
    }
    for(int i=0;i<count;i++) fwrite(&students[i],sizeof(Score),1,fp);
    fclose(fp);
    printf("\n\tSorting by total score completed!\n");
}

void sortByAverageScore() 
{
    Score students[100];
    int count=loadStudents(students,100);
    if(count==0) 
    {
        printf("\n\tNo student data to sort!\n");
        return;
    }

    quick_sort_average(students,0,count-1);
    FILE* fp=fopen("StudentGrade.dat","wb");
    if(!fp) 
    {
        printf("\n\tFile opening failed, sorting failed!\n");
        return;
    }
    for(int i=0;i<count;i++) fwrite(&students[i],sizeof(Score),1,fp);
    fclose(fp);
    printf("\n\tSorting by average score completed!\n");
}

bool getChoice(const char* prompt) 
{
    char choice;
    printf("%s",prompt);
    while(true) 
    {
        cin>>choice;
        if(choice=='y'||choice=='Y') 
        {
            clearInputBuffer();
            return true;
        } else if(choice=='n'||choice=='N')
        {
            clearInputBuffer();
            return false;
        } else printf("\tInvalid input, please re-enter (y/n):  ");
    }
}

bool InputStudentInformation() 
{
    Score s;
    system("cls");
    printf("\n\t===== Student Information Input =====");
    printf("\n\n\tPlease enter student ID (enter 0 to end):  ");
    if(scanf("%d",&s.StudentNum)!=1) {
        printf("\n\tInput error! Please enter a numeric student ID!\n");
        clearInputBuffer();
        system("pause");
        return true;
    }
    if(s.StudentNum==0) return false;
    Score temp[100];
    int count=loadStudents(temp,100);
    for(int i=0;i<count;i++) 
    {
        if(temp[i].StudentNum==s.StudentNum) 
        {
            printf("\n\tStudent ID %d already exists!\n",s.StudentNum);
            system("pause");
            return true;
        }
    }
    printf("\n\tPlease enter Chinese score (0-100):  ");
    while(scanf("%f",&s.ChineseScore)!=1||s.ChineseScore<0||s.ChineseScore>100) 
    {
        printf("\tInvalid score, please re-enter (0-100):  ");
        clearInputBuffer();
    }
    printf("\tPlease enter Math score (0-100):  ");
    while(scanf("%f",&s.MathScore)!=1||s.MathScore<0||s.MathScore>100)
    {
        printf("\tInvalid score, please re-enter (0-100):  ");
        clearInputBuffer();
    }
    printf("\tPlease enter English score (0-100):  ");
    while(scanf("%f",&s.EnglishScore)!=1||s.EnglishScore<0||s.EnglishScore>100) 
    {
        printf("\tInvalid score, please re-enter (0-100):  ");
        clearInputBuffer();
    }

    printf("\tPlease enter Physics score (0-100):  ");
    while(scanf("%f",&s.PhysicsScore)!=1||s.PhysicsScore<0||s.PhysicsScore>100) {
        printf("\tInvalid score, please re-enter (0-100):  ");
        clearInputBuffer();
    }

    printf("\tPlease enter Chemistry score (0-100):  ");
    while(scanf("%f",&s.ChemistryScore)!=1||s.ChemistryScore<0||s.ChemistryScore>100) {
        printf("\tInvalid score, please re-enter (0-100):  ");
        clearInputBuffer();
    }

    s.TotalScore=s.ChineseScore+s.MathScore+s.EnglishScore+s.PhysicsScore+s.ChemistryScore;
    s.AveScore=calculateAverage(s);

    if(saveStudentToFile(s)) printf("\n\tStudent information saved successfully!\n");
    else printf("\n\tFailed to save student information!\n");
    system("pause");
    return true;
}

void printAllStudents() {
    Score students[100];
    int count=loadStudents(students,100);
    if(count==0) {
        printf("\n\tNo student data!\n");
        return;
    }

    printf("\n======================= All Student Information ======================");
    printf("\nID\tChinese\tMath\tEnglish\tPhysics\tChemistry\tTotal\tAverage\n");
    for(int i=0;i<count;i++) {
        printf("%d\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t\t%.1f\t%.1f\n",
               students[i].StudentNum,
               students[i].ChineseScore,
               students[i].MathScore,
               students[i].EnglishScore,
               students[i].PhysicsScore,
               students[i].ChemistryScore,
               students[i].TotalScore,
               students[i].AveScore);
    }
}

int main() {
    if(!initFile()) {
        system("pause");
        return 1;
    }

    printf("\n\tStart entering student information (enter 0 to end)\n");
    while(InputStudentInformation());
    system("cls");

    if(getChoice("\tDo you want to sort by total score? (y/n):")) {
        sortByTotalScore();
        printAllStudents();
        system("pause");
        system("cls");
    }

    if(getChoice("\tDo you want to sort by average score? (y/n):")) {
        sortByAverageScore();
        printAllStudents();
        system("pause");
        system("cls");
    }

    printf("\n\tProgram ended!\n");
    return 0;
}