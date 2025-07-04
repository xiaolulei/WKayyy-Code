#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <random>
#include <vector>
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
    char From[20];
    char Profession[20];
};

void clearInputBuffer() 
{
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
}

void GradeStatistic()
{
    GradeStatistic_Start:
    system("cls");
    FILE *fp;
    fp = fopen("StudentGrade.dat", "rb");
    if (fp == NULL)
    {
        printf("================Grade Statistic=================");
        printf("\nCan not open the StudentGrade.dat ! ...");
        printf("\n=============================================\n");
        system("pause");
        return;
    }

    printf("================Grade Statistic=================");
    printf("\nPlease Enter the course you want! ...");
    printf("\nAvailable courses: Chinese, Math, English, Physics, Chemistry");
    printf("\n=============================================\n");
    
    char choice[20];
    int validInput = 0;
    
    while (!validInput)
    {
        cin >> choice;
        if (strcmp(choice, "Chinese") == 0 || strcmp(choice, "Math") == 0 || strcmp(choice, "English") == 0 || strcmp(choice, "Physics") == 0 || strcmp(choice, "Chemistry") == 0)
        {
            validInput = 1;
        }
        else
        {
            printf("Invalid course name! Please re-enter: ");
        }
    }

    int flag = 0;
    if (strcmp(choice, "Chinese") == 0) flag = 1;
    else if (strcmp(choice, "Math") == 0) flag = 2;
    else if (strcmp(choice, "English") == 0) flag = 3;
    else if (strcmp(choice, "Physics") == 0) flag = 4;
    else if (strcmp(choice, "Chemistry") == 0) flag = 5;

    float S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0;
    Score read;
    int count = 0;

    while (fread(&read, sizeof(Score), 1, fp))
    {
        count++;
        float score = 0;
        switch (flag)
        {
            case 1: score = read.ChineseScore; break;
            case 2: score = read.MathScore; break;
            case 3: score = read.EnglishScore; break;
            case 4: score = read.PhysicsScore; break;
            case 5: score = read.ChemistryScore; break;
        }
        if (score == 0) S1++;
        else if (score > 0 && score < 60) S2++;
        else if (score >= 60 && score < 75) S3++;
        else if (score >= 75 && score < 90) S4++;
        else S5++;
    }
    
    fclose(fp);

    if (count == 0)
    {
        printf("\nNo student data found!\n");
        system("pause");
        return;
    }

    // 输出统计结果
    printf("\n========== %s Grade Distribution ==========\n", choice);
    printf("--------------------------------------------------------------------\n");
    printf("| Grade Range  | Count | Percentage |\n");
    printf("|--------------|-------|------------|\n");
    printf("| 0            | %5.0f | %8.2f%% |\n", S1, S1/count*100);
    printf("| (0,60)       | %5.0f | %8.2f%% |\n", S2, S2/count*100);
    printf("| [60,75)      | %5.0f | %8.2f%% |\n", S3, S3/count*100);
    printf("| [75,90)      | %5.0f | %8.2f%% |\n", S4, S4/count*100);
    printf("| [90,100]     | %5.0f | %8.2f%% |\n", S5, S5/count*100);
    printf("--------------------------------------------------------------------\n");
    printf(" Total students: %d\n", count);
    printf("=============================================\n");
    system("pause");
    printf("=================Sort Student==================");
    printf("Do you want to Continue? ... ");
    char endchoice;
    do
    {
        cin >> endchoice ;
    }while(endchoice != 'y' && endchoice != 'Y' && endchoice != 'N' && endchoice != 'n');
    if(endchoice == 'y' || endchoice == 'Y')
    {
        goto GradeStatistic_Start;
    }
    else return ;
}

void sort_by_From() 
{
    sort_by_From_Start:
    system("cls");
    float max = 1e-9;
    float min = 1e9;
    float ave = 0;
    float mid = 0;
    float all_score = 0;
    int Count = 0;
    FILE *fp1 , *fp2;
    fp1 = fopen ("StudentInformation.dat","rb");
    if(fp1 == NULL)
    {
        printf("=================Sort Student==================");
        printf("\nCan not open the StudentInformation.dat ! ...");
        printf("\n=============================================\n");
        system("pause");
        return ;
    }
    fp2 = fopen ("StudentGrade.dat","rb");
    if(fp2 == NULL)
    {
        printf("=================Sort Student==================");
        printf("\nCan not open the StudentGrade.dat ! ...");
        printf("\n=============================================\n");
        system("pause");
        return ;
    }
    Student read1;
    Score read2;
    char sort_by_From_choice[20];
    printf("=================Sort Student=====================");
    printf("\nPlease Enter the Profession you want to sort ! ...");
    printf("\n==================================================\n");
    cin >> sort_by_From_choice;//注意！这里只能填写A或者B
    vector<float> scores;
    
    int flag;
    if(strcmp(sort_by_From_choice, "A") == 0) flag = 1;
    else flag = 0;
    
    while(fread(&read1, sizeof(Student), 1, fp1))
    {
        rewind(fp2);
        if((strcmp(read1.From, "A") == 0) && flag)
        {
            while(fread(&read2, sizeof(Score), 1, fp2))
            {
                if(read1.StudentNum == read2.StudentNum)
                {
                    Count++;
                    if(read2.TotalScore > max) max = read2.TotalScore;
                    if(read2.TotalScore < min) min = read2.TotalScore;
                    all_score += read2.TotalScore;
                    scores.push_back(read2.TotalScore);
                    break;
                }
            }
        }
        if((strcmp(read1.From, "B") == 0) && !flag)
        {
            while(fread(&read2, sizeof(Score), 1, fp2))
            {
                if(read1.StudentNum == read2.StudentNum)
                {
                    Count++;
                    if(read2.TotalScore > max) max = read2.TotalScore;
                    if(read2.TotalScore < min) min = read2.TotalScore;
                    all_score += read2.TotalScore;
                    scores.push_back(read2.TotalScore);
                    break;
                }
            }
        }
    }
    if(Count > 0) 
    {
        ave = all_score / Count;
        if(!scores.empty()) 
        {
            sort(scores.begin(), scores.end()); 
            if(scores.size() % 2 == 0) 
            {
                mid = (scores[scores.size()/2 - 1] + scores[scores.size()/2]) / 2.0;
            } else 
            {
                mid = scores[scores.size()/2];
            }
        }
    }
    printf("=================Sort Student==================");
    printf("\nStatistics (From %s):\n", sort_by_From_choice);
    printf("Highest Score: %.2f\n", max);
    printf("Lowest Score: %.2f\n", min);
    printf("Average Score: %.2f\n", ave);
    printf("Median Score: %.2f\n", mid);
    printf("Total Students: %d\n", Count);
    printf("\n=============================================\n");
    fclose(fp1);
    fclose(fp2);
    system("pause");
    system("cls");
    printf("=================Sort Student==================");
    printf("Do you want to Continue? ... ");
    char choice;
    do
    {
        cin >> choice ;
    }while(choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n');
    if(choice == 'y' || choice == 'Y')
    {
        goto sort_by_From_Start;
    }
    else return ;
}

void sort_by_Profession()
{
    sort_by_Profession_Start:
    system("cls");
    float max = 1e-9;
    float min = 1e9;
    float ave = 0;
    float mid = 0;
    float all_score = 0;
    int Count = 0;
    FILE *fp1 , *fp2;
    fp1 = fopen ("StudentInformation.dat","rb");
    if(fp1 == NULL)
    {
        printf("=================Sort Student==================");
        printf("\nCan not open the StudentInformation.dat ! ...");
        printf("\n=============================================\n");
        system("pause");
        return ;
    }
    fp2 = fopen ("StudentGrade.dat","rb");
    if(fp2 == NULL)
    {
        printf("=================Sort Student==================");
        printf("\nCan not open the StudentGrade.dat ! ...");
        printf("\n=============================================\n");
        system("pause");
        return ;
    }
    Student read1;
    Score read2;
    char sort_by_Profession_choice[20];
    printf("=================Sort Student==================");
    printf("\nPlease Enter the Place you want to sort ! ...");
    printf("\n=============================================\n");
    cin >> sort_by_Profession_choice;//注意！这里只能填写A或者B
    vector<float> scores;
    
    int flag;
    if(strcmp(sort_by_Profession_choice, "A") == 0) flag = 1;
    else flag = 0;
    
    while(fread(&read1, sizeof(Student), 1, fp1))
    {
        rewind(fp2);
        if((strcmp(read1.Profession, "A") == 0) && flag)
        {
            while(fread(&read2, sizeof(Score), 1, fp2))
            {
                if(read1.StudentNum == read2.StudentNum)
                {
                    Count++;
                    if(read2.TotalScore > max) max = read2.TotalScore;
                    if(read2.TotalScore < min) min = read2.TotalScore;
                    all_score += read2.TotalScore;
                    scores.push_back(read2.TotalScore);
                    break;
                }
            }
        }
        if((strcmp(read1.Profession, "B") == 0) && !flag)
        {
            while(fread(&read2, sizeof(Score), 1, fp2))
            {
                if(read1.StudentNum == read2.StudentNum)
                {
                    Count++;
                    if(read2.TotalScore > max) max = read2.TotalScore;
                    if(read2.TotalScore < min) min = read2.TotalScore;
                    all_score += read2.TotalScore;
                    scores.push_back(read2.TotalScore);
                    break;
                }
            }
        }
    }
    if(Count > 0) 
    {
        ave = all_score / Count;
        if(!scores.empty()) 
        {
            sort(scores.begin(), scores.end()); 
            if(scores.size() % 2 == 0) 
            {
                mid = (scores[scores.size()/2 - 1] + scores[scores.size()/2]) / 2.0;
            } else 
            {
                mid = scores[scores.size()/2];
            }
        }
    }
    printf("=================Sort Student==================");
    printf("\nStatistics (Profession %s):\n", sort_by_Profession_choice);
    printf("Highest Score: %.2f\n", max);
    printf("Lowest Score: %.2f\n", min);
    printf("Average Score: %.2f\n", ave);
    printf("Median Score: %.2f\n", mid);
    printf("Total Students: %d\n", Count);
    printf("\n=============================================\n");
    fclose(fp1);
    fclose(fp2);
    system("pause");
    system("cls");
    printf("=================Sort Student==================");
    printf("Do you want to Continue? ... ");
    char choice;
    do
    {
        cin >> choice ;
    }while(choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n');
    if(choice == 'y' || choice == 'Y')
    {
        goto sort_by_Profession_Start;
    }
    else return ;

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
    printf("\n3.Sort Student by From");
    printf("\n4.Sort Student by Profession");
    printf("\n5.Grade Statistic");
    printf("\n0.Exit System");
    printf("\n=================================");
    printf("\nPlease enter your choice:   ");
    int mainChoice;
    do
    {
    cin >> mainChoice;
    }while(mainChoice!=1&&mainChoice!=2&&mainChoice!=3&&mainChoice!=4&&mainChoice!=5&&mainChoice!=0);
    if(mainChoice == 1)
    {
        RadomSelect();
    }
    else if(mainChoice == 0)
    {
        system("cls");
        printf("======Student Manage System======");
        printf("\n\tProgram ended!\n");
        printf("=================================");
    }
    else if(mainChoice == 3)
    {
        sort_by_From();
    }
    else if(mainChoice == 4)
    {
        sort_by_Profession();
    }
    else if(mainChoice == 5)
    {
        GradeStatistic();
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