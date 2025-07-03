#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <random>
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

struct Student
{
    int StudentNum;
    char StudentName[20];
};

void clearInputBuffer() 
{
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
}

void RadomStudentInfromationInput()//仅用于管理员输入数据进行debug
{
    FILE *fp;
    fp = fopen("StudentInformation.dat","wb");
    Student write;
    do
    {
        printf("Please enter StudentNum:(Input 0 to exit)  ");
        cin >> write.StudentNum;
        if(write.StudentNum == 0)
        {
            exit(0);
        }
        printf("\nPlease enter StudentName:  ");
        cin >> write.StudentName;
        fwrite(&write,sizeof(Student),1,fp);
    }while(1);
}

int StudentALL = 10;

void RadomSelect()
{
    RadomStart:
    FILE *fp , *temp_file;
    temp_file = fopen("TempFile.dat","wb");
    Student Read;//假定学生上限为100;
    fp = fopen("StudentInformation.dat","r+b");
    if(fp == NULL)
    {
        printf("================Radom Student==================");
        printf("\nCan not open the StudentInformation.dat ! ...");
        printf("\n=============================================\n");
        exit(0);
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1,StudentALL); //假定有是个数据，如果有更更多可以把10改成更大的数字
    int radom_int = dis(gen);
    int StudentCounts = 0;
    int iffind = 0;
    rewind(fp);
    while(fread(&Read,sizeof(Student),1,fp))
    {
        StudentCounts++;
        if((StudentCounts == radom_int) && !iffind)
        {
            system("cls");
            printf("=========Radom Student=========");
            printf("\nStudent's Num:  %d",Read.StudentNum);
            printf("\nStudent's Name: %s",Read.StudentName);
            printf("\n===============================\n");
            printf("press any key to continue ...");
            clearInputBuffer();
            getchar();
            iffind = 1;
            continue;
        }
        fwrite(&Read,sizeof(Student),1,temp_file);
    }
    fclose(fp);
    fclose(temp_file);
    if(iffind)
    {
        remove("StudentInformation.dat");
        rename("TempFile.dat","StudentInformation.dat");
        StudentALL--;
    }
    else
    {
        remove("TempFile.dat");
        system("cls");
        printf("=========Radom Student=========");
        printf("\nCan not find this Student ! ...");
        printf("\n===============================\n");
        system("pause");
        clearInputBuffer();
    }
    char RadomSortChoice;
    do
    {
        system("cls");
        printf("=========Radom Student=========");
        printf("\nDo you want to select another one : (y/n)");
        cin >> RadomSortChoice;
    }while(RadomSortChoice != 'y' && RadomSortChoice != 'Y' && RadomSortChoice != 'n' && RadomSortChoice != 'N');
    if(RadomSortChoice == 'y' || RadomSortChoice == 'Y')
    {
        goto RadomStart;
    }
    else
    {
        return ;
    }
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
    //RadomStudentInfromationInput();
    system("cls");
    printf("======Student Manage System======");
    printf("\n1.Radom Select Student");
    printf("\n2.Student Infromation Manage");
    printf("\n=================================");
    printf("\nPlease enter your choice:   ");
    int mainChoice;
    do
    {
    cin >> mainChoice;
    }while(mainChoice!=1&&mainChoice!=2);
    if(mainChoice == 1)
    {
        RadomSelect();
    }
    else
    {
        if(!initFile()) 
        {
            system("pause");
            return 1;
        }

        printf("\n\tStart entering student information (enter 0 to end)\n");
        while(InputStudentInformation());
        system("cls");

        if(getChoice("\tDo you want to sort by total score? (y/n):")) 
        {
            sortByTotalScore();
            printAllStudents();
            system("pause");
            system("cls");
        }

        if(getChoice("\tDo you want to sort by average score? (y/n):")) 
        {
            sortByAverageScore();
            printAllStudents();
            system("pause");
            system("cls");
        }
    }
    system("cls");
    printf("======Student Manage System======");
    printf("\n\tProgram ended!\n");
    printf("=================================");
    return 0;
}