#include <iostream>
#include <cstdlib>
#include <cstring>
#include "prog.h"

using namespace std;

/*-----------------------------------------------*/

void Sort() {
    char xz[8];
    system("cls");
    printf("\n\n      0--return");
    printf("\n\n      1--student table on student' num");
    printf("\n\n      2--course table on course' num");
    printf("\n\n      3--score table on first student' num and next course' num");
    printf("\n\n      4--score table on first course' num and next student' num");
    printf("\n\n      please choise: (0, 1, 2, 3, 4): ");
    do {
        gets(xz);
    } while (xz[0]!='0' && xz[0]!='1' && xz[0]!='2' && xz[0]!='3' && xz[0]!='4');
    system("cls");
    switch(xz[0]){
        case '0': return;
        case '1': {   // 学生表按学号升序排序
            int count=0, i, j, post;    
            FILE *fp;
            // 定义学生表的结构体数组stud[100], 结构体指针变量p和结构体指针数组pst[100]
            StudentTab *p, stud[100], *pst[100];
            if ((fp=fopen("8888STUD.dat", "rb"))==0) 
            { 
                printf("\n\nCannot open STUDENT data file!\n");
                system("pause");
                break;
            }
            // 将学生文件中的记录逐一读入数组stud[100]中，并统计学生记录数count
            fread(&stud[count], sizeof(StudentTab), 1, fp);   // 从学生文件中读取一个学生记录
            pst[count]=&stud[count];    // 使指针数组元素pst[count]指向学生结构体数组元素stud[count]
            while (!feof(fp)) // 依次处理学生文件中的每一个学生记录
            {    
                count++;
                fread(&stud[count], sizeof(StudentTab), 1, fp);   // 从学生文件中读取下一个学生记录
                // 将学生文件中的记录逐一读入数组stud[100]中，并统计学生记录数count
                pst[count]=stud+count;    // 使指针数组元素pst[count]指向学生结构体数组元素stud[count]
            }
            for (i=0; i<count-1; i++) {      // 用选择法通过指针数组对结构体数组按学号进行升序排序
                post=i;
                for (j=i+1; j<count; j++)
                    if (strcmp(pst[j]->num, pst[post]->num)<0) post=j;
                if (post!=i) {        // 交换指针数组元素的指向
                    p=pst[i]; pst[i]=pst[post]; pst[post]=p;
                }
            }
            fclose(fp);
	        if ((fp=fopen("8888STUD.dat", "w+b"))==0) {
                printf("\n\nCannot open STUDENT data file!\n");
                system("pause");
                break;
            }
            for (i=0; i<count; i++)       // 将排序后的学生记录逐条写回文件中
                fwrite(pst[i], sizeof(StudentTab), 1, fp);
            fclose(fp);
            system("cls");
            printf("\n\n\t\tThe sort of student table is over. ");
            system("pause");
            break;
        }
        case '2': {   // 课程表按课程代码升序排序
            int count=0, i, j, post;    
            FILE *fp;
            // 定义学生表的结构体数组stud[100], 结构体指针变量p和结构体指针数组pst[100]
            CourseTab *p, cour[100], *pst[100];
            if ((fp=fopen("8888COUR.dat", "rb"))==0) 
            { 
                printf("\n\nCannot open COURSE data file!\n");
                system("pause");
                break;
            }
            // 将学生文件中的记录逐一读入数组stud[100]中，并统计学生记录数count
            fread(&stud[count], sizeof(CourseTab), 1, fp);   // 从学生文件中读取一个学生记录
            pst[count]=&cour[count];    // 使指针数组元素pst[count]指向学生结构体数组元素stud[count]
            while (!feof(fp)) // 依次处理学生文件中的每一个学生记录
            {    
                count++;
                fread(&cour[count], sizeof(CourseTab), 1, fp);   // 从学生文件中读取下一个学生记录
                // 将学生文件中的记录逐一读入数组stud[100]中，并统计学生记录数count
                pst[count]=cour+count;    // 使指针数组元素pst[count]指向学生结构体数组元素stud[count]
            }
            for (i=0; i<count-1; i++) {      // 用选择法通过指针数组对结构体数组按学号进行升序排序
                post=i;
                for (j=i+1; j<count; j++)
                    if (strcmp(pst[j]->coursenum, pst[post]->coursenum)<0) post=j;
                if (post!=i) {        // 交换指针数组元素的指向
                    p=pst[i]; pst[i]=pst[post]; pst[post]=p;
                }
            }
            fclose(fp);
	        if ((fp=fopen("8888COUR.dat", "w+b"))==0) {
                printf("\n\nCannot open STUDENT data file!\n");
                system("pause");
                break;
            }
            for (i=0; i<count; i++)       // 将排序后的学生记录逐条写回文件中
                fwrite(pst[i], sizeof(CourseTab), 1, fp);
            fclose(fp);
            system("cls");
            printf("\n\n\t\tThe sort of course table is over. ");
            system("pause");
            break;
        }
        case '3': {   // 成绩表按先学号、后课程代码升序排序
            int count=0, i, j, post;    
            FILE *fp;
            ScoreTab *p, scor[100], *pst[100];
            if ((fp=fopen("8888SCOR.dat", "rb"))==0) 
            { 
                printf("\n\nCannot open SCORE data file!\n");
                system("pause");
                break;
            }
            fread(&scor[count], sizeof(ScoreTab), 1, fp);  
            pst[count]=&scor[count];    
            while (!feof(fp)) 
            {    
                count++;
                fread(&scor[count], sizeof(ScoreTab), 1, fp); 
                pst[count]=scor+count;   
            }
            for (i=0; i<count-1; i++) {    
                post=i;
                for (j=i+1; j<count; j++)
                    if (pst[j]->score < pst[post]->score) post=j;
                    else if(pst[j]->score == pst[post]->score)
                    {
                        if(strcmp(pst[j]->coursenum, pst[post]->coursenum) < 1)
                        post = j;
                        else continue;
                    }
                if (post!=i) {        // 交换指针数组元素的指向
                    p=pst[i]; pst[i]=pst[post]; pst[post]=p;
                }
            }
            fclose(fp);
	        if ((fp=fopen("8888SCOR.dat", "w+b"))==0) {
                printf("\n\nCannot open SCORE data file!\n");
                system("pause");
                break;
            }
            for (i=0; i<count; i++)       // 将排序后的学生记录逐条写回文件中
                fwrite(pst[i], sizeof(ScoreTab), 1, fp);
            fclose(fp);
            system("cls");
            printf("\n\n\t\tThe sort of score table is over. ");
            system("pause");
            break;
        }
        case '4': {   // 成绩表按先课程代码、后学号升序排序
            int count=0, i, j, post;    
            FILE *fp;
            ScoreTab *p, scor[100], *pst[100];
            if ((fp=fopen("8888SCOR.dat", "rb"))==0) 
            { 
                printf("\n\nCannot open SCORE data file!\n");
                system("pause");
                break;
            }
            fread(&scor[count], sizeof(ScoreTab), 1, fp);  
            pst[count]=&scor[count];    
            while (!feof(fp)) 
            {    
                count++;
                fread(&scor[count], sizeof(ScoreTab), 1, fp); 
                pst[count]=scor+count;   
            }
            for (i=0; i<count-1; i++) {    
                post=i;
                for (j=i+1; j<count; j++)
                    if ((pst[j]->coursenum, pst[post]->coursenum) < 1) post=j; 
                    else if((pst[j]->coursenum, pst[post]->coursenum) == 1)
                    {
                        if(pst[j]->score < pst[post]->score)
                        post = j;
                        else continue;
                    }
                if (post!=i) {        // 交换指针数组元素的指向
                    p=pst[i]; pst[i]=pst[post]; pst[post]=p;
                }
            }
            fclose(fp);
	        if ((fp=fopen("8888SCOR.dat", "w+b"))==0) {
                printf("\n\nCannot open SCORE data file!\n");
                system("pause");
                break;
            }
            for (i=0; i<count; i++)       // 将排序后的学生记录逐条写回文件中
                fwrite(pst[i], sizeof(ScoreTab), 1, fp);
            fclose(fp);
            system("cls");
            printf("\n\n\t\tThe sort of score table is over. ");
            system("pause");
            break;
        }
    }
}


void AutoCompute()
{ 
    fflush(stdin);
    // 自动计算每一个学生所选修课程的门数和加权平均成绩
    char ch[10];
    long pos;
    int count, creditSum;
    float scoreSum;
    FILE *fp1, *fp2, *fp3;
    StudentTab bt; // 定义学生表的结构体变量bt
    CourseTab ct;  // 定义课程表的结构体变量ct
    ScoreTab st;   // 定义成绩表的结构体变量st
    if ((fp1 = fopen("8888STUD.dat", "r+b")) == 0)
    {
        printf("\n\nCannot open STUDENT data file!\n");
        system("pause");
        return;
    }
    if ((fp2 = fopen("8888COUR.dat", "rb")) == 0)
    {
        printf("\n\nCannot open COURSE data file!\n");
        fclose(fp1);
        system("pause");
        return;
    }
    if ((fp3 = fopen("8888SCOR.dat", "rb")) == 0)
    {
        printf("\n\nCannot open SCORE data file!\n");
        fclose(fp1);
        fclose(fp2);
        system("pause");
        return;
    }
    system("cls");
    printf("\n\nAuto computing, Please waiting......\n");
    pos = ftell(fp1);                       // 保留要读取的学生记录在学生文件中的位移量，以便重新定位该记录进行更新
    fread(&bt, sizeof(StudentTab), 1, fp1); // 从学生文件中读取一个学生记录
    system("cls");
    while (!feof(fp1))
    { 
        // 依次计算学生文件中每一个学生记录的已选修课程门数、加权平均成绩
        count = 0;
        creditSum = 0;
        scoreSum = 0;
        rewind(fp3);                          // 复位到成绩文件头
        fread(&st, sizeof(ScoreTab), 1, fp3); // 从成绩文件中读取一个成绩记录
        while (!feof(fp3))
        { 
            // 在成绩文件中查找bt.num学生选修的所有课程的成绩记录
            // 请在此处补充代码计算每个学生的已修学分以及已获学分课程加权平均分
            if(strcmp(bt.num,st.num) == 0)
            {
                count++;
                rewind(fp2);
                while(fread(&ct,sizeof(CourseTab),1,fp2))
                {
                    if(strcmp(st.coursenum,ct.coursenum) == 0)
                    {
                        scoreSum+=st.score * ct.credit;
                        creditSum+=ct.credit;
                        break;
                    }
                }
            } 
            fread(&st, sizeof(ScoreTab), 1, fp3); // 从成绩文件中读取一个成绩记录
        }
        bt.counts = count; // 用计算得到的汇总值更新学生结构体变量bt的对应成员值
        if (creditSum != 0)
            bt.aver = scoreSum / creditSum; // 注意：分母不能为0
        else
            bt.aver = 0.0;
        bt.credits = creditSum;
        fseek(fp1, pos, SEEK_SET);               // 在学生文件中定位正在进行汇总计算的学生记录
        fwrite(&bt, sizeof(StudentTab), 1, fp1); // 用学生结构体变量bt更新学生文件中已定位的学生记录内容
        pos = pos + sizeof(StudentTab);          // 计算下一个待处理学生记录的位移量(即当前记录的下一个记录的位移量)
        fseek(fp1, pos, SEEK_SET);               // 在学生文件中定位下一个待处理的学生记录
        fread(&bt, sizeof(StudentTab), 1, fp1);  // 从学生文件中读取一个学生记录
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    system("cls");
    printf("=========================================================");
    printf("\nAuto computation is over. ");
    printf("\n=========================================================");
    system("pause");
}

void FindRec()
{ /*记录方式查找*/
    char xz[8];
    system("cls");
    printf("\n\n                    0--return");
    printf("\n\n                    1--student infomation");
    printf("\n\n                    2--course infomation");
    printf("\n\n                    3--student score");
    printf("\n\n                    Please choise: (0, 1, 2, 3):  ");
    do
    {
        gets(xz);
    } while (xz[0] != '0' && xz[0] != '1' && xz[0] != '2' && xz[0] != '3');
    system("cls");
    switch (xz[0])
    {
    case '0':
        return;
    case '1':
    { // 按学号查找学生基本信息
        int find, flag = 0, len = 0, start, end, mid;
        char ch[30], num[10];
        FILE *fp, *fpIdx;
        StudentTab t;           // 定义学生表的结构体变量t
        StudentIdxTab idx[100]; // 定义学生索引表的结构体数组idx[100]
        if ((fp = fopen("8888STUD.dat", "rb")) == 0)
        {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause");
            break;
        }
        if ((fpIdx = fopen("8888SIDX.dat", "rb")) != 0)
        {
            if (fread(&idx[len], sizeof(StudentIdxTab), 1, fpIdx))
                flag = 1; // 从学生索引文件中读取一个索引项
            while (!feof(fpIdx))
            {                                                      // 将学生索引文件中的索引项依次读入学生索引结构体数组idx中
                len++;                                             // 学生索引文件中索引项的个数
                fread(&idx[len], sizeof(StudentIdxTab), 1, fpIdx); // 从学生索引文件中读取一个索引项
            }
        }
    F1:
        printf("\n\nPlease input Student's num:  ");
        gets(num); // 输入需修改学生记录的学号到字符数组num
        find = 0;
        if (flag)
        { // 存在学生索引文件时，则在学生索引文件中进行折半查找——利用索引文件可加快查找速度
            start = 0;
            end = len - 1; // 在学生索引结构体数组idx中折半查找索引码值为num的索引项
            while (start <= end)
            {
                mid = (start + end) / 2;
                if (strcmp(idx[mid].num, num) < 0)
                    start = mid + 1; // 往右继续折半查找
                else if (strcmp(idx[mid].num, num) > 0)
                    end = mid - 1; // 往左继续折半查找
                else
                    break; // 找到了待查找学生记录的索引项(第m个索引项)，结束查找
            }
            if (start <= end)
            { // 折半查找成功，该学生记录在学生文件中的位移量是idx[mid].offset
                find = 1;
                fseek(fp, idx[mid].offset, SEEK_SET); // 在学生文件中定位待查找的学生记录
                fread(&t, sizeof(StudentTab), 1, fp); // 从学生文件中读取一个学生记录
            }
            // 说明：也可以直接针对学生索引文件进行折半查找
        }
        else
        {                                         // 不存在学生索引文件时，则在学生文件中进行顺序扫描查找
            rewind(fp);                           // 复位到学生文件头
            fread(&t, sizeof(StudentTab), 1, fp); // 从学生文件中读取一个学生记录
            while (!feof(fp))
            { // 在学生文件中顺序查找学号num的学生记录，找到后再显示
                if (strcmp(t.num, num) == 0)
                { // 如果在学生文件中找到了给定学号num的学生记录
                    find = 1;
                    break; // 找到了，则结束顺序查找
                }
                fread(&t, sizeof(StudentTab), 1, fp); // 从学生文件中读取一个学生记录
            }
        }
        system("cls");
        if (find)
        { // 如果找到了，则显示该学生信息
            // 在屏幕上显示该学生记录
            printf("\n\n===================================================");
            printf("\n num :     %-s", t.num);
            printf("\n name :    %-s", t.name);
            printf("\n sex :     %-c", t.sex);
            printf("\n birthday: %d-%d-%d", t.birthday.year, t.birthday.month, t.birthday.day);
            printf("\n phone :   %-s", t.phone);
            printf("\n counts :  %d", t.counts);
            printf("\n average : %.2f", t.aver);
            printf("\n==================================================");
        }
        else
        {
            system("cls");
            printf("\n\n\t\tNot find record");
        }
        do
        {
            printf("\n\nCountinue?(y/n): ");
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y')
            goto F1; // 实际上是构成循环
        else
            fclose(fp);
        break;
    }
    case '2':
    {
        int find, flag = 0, len = 0, start, end, mid;
        char ch[30], num[10];
        FILE *fp, *fpIdx;
        CourseTab t;           // 定义学生表的结构体变量t
        CourseIdxTab idx[100]; // 定义学生索引表的结构体数组idx[100]
        if ((fp = fopen("8888COUR.dat", "rb")) == 0)
        {
            printf("\n\nCannot open COURSE data file!\n");
            system("pause");
            break;
        }
        if ((fpIdx = fopen("8888CIDX.dat", "rb")) != 0)
        {
            if (fread(&idx[len], sizeof(CourseIdxTab), 1, fpIdx))
                flag = 1;
            while (!feof(fpIdx))
            {
                len++;                                            // 学生索引文件中索引项的个数
                fread(&idx[len], sizeof(CourseIdxTab), 1, fpIdx); // 从学生索引文件中读取一个索引项
            }
        }
    F2:
        printf("\n\nPlease input Course's num:  ");
        gets(num);
        find = 0;
        if (flag)
        {
            start = 0;
            end = len - 1; // 在学生索引结构体数组idx中折半查找索引码值为num的索引项
            while (start <= end)
            {
                mid = (start + end) / 2;
                if (strcmp(idx[mid].coursenum, num) < 0)
                    start = mid + 1; // 往右继续折半查找
                else if (strcmp(idx[mid].coursenum, num) > 0)
                    end = mid - 1; // 往左继续折半查找
                else
                    break; // 找到了待查找学生记录的索引项(第m个索引项)，结束查找
            }
            if (start <= end)
            { // 折半查找成功，该学生记录在学生文件中的位移量是idx[mid].offset
                find = 1;
                fseek(fp, idx[mid].offset, SEEK_SET); // 在学生文件中定位待查找的学生记录
                fread(&t, sizeof(CourseTab), 1, fp);  // 从学生文件中读取一个学生记录
            }
        }
        else
        {                                        // 不存在学生索引文件时，则在学生文件中进行顺序扫描查找
            rewind(fp);                          // 复位到学生文件头
            fread(&t, sizeof(CourseTab), 1, fp); // 从学生文件中读取一个学生记录
            while (!feof(fp))
            { // 在学生文件中顺序查找学号num的学生记录，找到后再显示
                if (strcmp(t.coursenum, num) == 0)
                { // 如果在学生文件中找到了给定学号num的学生记录
                    find = 1;
                    break; // 找到了，则结束顺序查找
                }
                fread(&t, sizeof(CourseTab), 1, fp); // 从学生文件中读取一个学生记录
            }
        }
        system("cls");
        if (find)
        {
            printf("\n\n===================================================");
            printf("\n CourseNum :     %-s", t.coursenum);
            printf("\n CourseName :    %-s", t.coursename);
            printf("\n Credit :     %-d", t.credit);
            printf("\n CourseHour :   %-d", t.coursehour);
            printf("\n Teachername :  %s", t.teachername);
            printf("\n==================================================");
        }
        else
        {
            system("cls");
            printf("\n\n\t\tNot find record");
        }
        do
        {
            printf("\n\nCountinue?(y/n): ");
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y')
            goto F2;
        else
            fclose(fp);
        break;
    }
    case '3':
    {
        int find, len = 0, start, end, mid;
        char ch[30], num[10];
        FILE *fp;
        ScoreTab t; // 定义学生表的结构体变量t
        if ((fp = fopen("8888SCOR.dat", "rb")) == 0)
        {
            printf("\n\nCannot open SCOR data file!\n");
            system("pause");
            break;
        }
    F3:
        printf("\n\nPlease input Student's num:  ");
        gets(num);
        find = 0;
        rewind(fp);                         // 复位到学生文件头
        fread(&t, sizeof(ScoreTab), 1, fp); // 从学生文件中读取一个学生记录
        while (!feof(fp))
        { // 在学生文件中顺序查找学号num的学生记录，找到后再显示
            if (strcmp(t.num, num) == 0)
            { // 如果在学生文件中找到了给定学号num的学生记录
                find = 1;
                break; // 找到了，则结束顺序查找
            }
            fread(&t, sizeof(ScoreTab), 1, fp); // 从学生文件中读取一个学生记录
        }
        system("cls");
        if (find)
        {
            printf("\n\n===================================================");
            printf("\n num :     %-s", t.num);
            printf("\n CourseNum :    %-s", t.coursenum);
            printf("\n NormalScore :     %-d", t.normalscore);
            printf("\n TestScore :   %-d", t.testscore);
            printf("\n Score :  %d", t.score);
            printf("\n==================================================");
        }
        else
        {
            system("cls");
            printf("\n\n\t\tNot find record");
        }
        do
        {
            printf("\n\nCountinue?(y/n): ");
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y')
            goto F3;
        else
            fclose(fp);
        break;
    }
    }
}

void ModiFile()
{ // 修改文件中的记录
    char xz[8];
    system("cls");
    printf("\n\n                    0--return");
    printf("\n\n                    1--student infomation");
    printf("\n\n                    2--course infomation");
    printf("\n\n                    3--student score");
    printf("\n                    Please choise: (0, 1, 2, 3):  ");
    do
    {
        gets(xz);
    } while (xz[0] != '0' && xz[0] != '1' && xz[0] != '2' && xz[0] != '3');
    switch (xz[0])
    {
    case '0':
        return;
    case '1':
    { // 按学号修改学生基本信息
        int find, repeat;
        long pos;
        char xz[8], ch[30], num[10];
        FILE *fp;
        StudentTab t, x; // 定义学生表的结构体变量t, x
        if ((fp = fopen("8888STUD.dat", "r+b")) == 0)
        {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause");
            break;
        }
    F1:
        system("cls");
        printf("\n\t\tPlease input Student's num:  ");
        gets(num); // 输入需修改学生记录的学号到字符数组num
        find = 0;
        rewind(fp);                           // 复位到学生文件头
        pos = ftell(fp);                      // 保留要读取的学生记录在学生文件中的位移量，以便重新定位该记录进行更新
        fread(&t, sizeof(StudentTab), 1, fp); // 从学生文件中读取一个学生记录
        while (!feof(fp))
        { // 需要在学生文件中找到学号num的学生记录，找到后再进行修改
            if (!feof(fp) && strcmp(t.num, num) == 0)
            {
                // 如果读取的学生记录是给定学号num的学生记录，即找到了需要修改的学生记录
                find = 1;
                break; // 结束查找
            }
            pos = ftell(fp);                      // 保留要读取的学生记录在学生文件中的位移量，以便重新定位该记录进行更新
            fread(&t, sizeof(StudentTab), 1, fp); // 从学生文件中读取一个学生记录
        }
        if (find)
        { // 如果找到了给定学号num的学生记录，则进行修改
        F11:
            system("cls");
            // 在屏幕上显示该学生记录的原来值
            printf("\n\n==================================================");
            printf("\n num :      %-s", t.num);
            printf("\n name :     %-s", t.name);
            printf("\n sex :      %-c", t.sex);
            printf("\n birthday : %d-%d-%d", t.birthday.year, t.birthday.month, t.birthday.day);
            printf("\n phone :    %-s", t.phone);
            printf("\n==================================================");
            // 输入该学生记录的新值（直接回车表示该属性的值不需要修改）
            printf("\n\nNew num : ");
            gets(ch); // 输入一个修改后的学号到字符数组ch
            if (strlen(ch) > 0 && strcmp(num, ch) != 0)
            { // 如果输入了一个新的学号ch
                repeat = 0;
                rewind(fp);                           // 复位到学生文件头
                fread(&x, sizeof(StudentTab), 1, fp); // 从学生文件中读取一个学生记录
                while (!feof(fp))
                { // 判断新输入的学号ch是否在学生文件中已经存在
                    if (strcmp(x.num, ch) == 0)
                    { // 如果在学生文件中找到了给定学号ch的学生记录
                        repeat = 1;
                        break; // 结束查找
                    }
                    fread(&x, sizeof(StudentTab), 1, fp); // 从学生文件中读取一个学生记录
                }
                if (repeat)
                { // 修改后的学号ch在学生文件中已经存在，重复了！
                    printf("\n\n\n\tThe student %s has existed!  Continue modify? (y/n)  ", ch);
                    do
                    {
                        gets(ch);
                        if (ch[0] == 'y' || ch[0] == 'Y')
                            goto F11;
                        else
                        {
                            fclose(fp);
                            return;
                        }
                    } while (ch[0] != 'y' && ch[0] != 'Y' && ch[0] != 'n' && ch[0] != 'N');
                }
                strcpy(t.num, ch); // 将学号ch字符串拷贝到学生结构体变量t的学号成员num
            }
            printf(" name : ");
            gets(ch); // 继续修改学生的其他成员
            if (strlen(ch) > 0)
                strcpy(t.name, ch); // 如果输入了新的值，则更新学生结构体变量t的相应成员值
            printf(" sex : ");
            gets(ch);
            if (strlen(ch) > 0)
                t.sex = ch[0];
            printf(" birthday : year:  ");
            gets(ch);
            if (strlen(ch) > 0)
                t.birthday.year = atoi(ch);
            printf("           month: ");
            gets(ch);
            if (strlen(ch) > 0)
                t.birthday.month = atoi(ch);
            printf("           day:   ");
            gets(ch);
            if (strlen(ch) > 0)
                t.birthday.day = atoi(ch);
            printf(" phone :");
            gets(ch);
            if (strlen(ch) > 0)
                strcpy(t.phone, ch);
            printf("==================================================");
            fseek(fp, pos, SEEK_SET);              // 在学生文件中定位正在修改的学生记录
            fwrite(&t, sizeof(StudentTab), 1, fp); // 用学生结构体变量t更新学生文件中已定位的学生记录内容
        }
        else
            printf("\n\n\n\t\tNo find record.\n");
        do
        {
            printf("\n\n\t\tModify another record? (y/n) ");
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y')
            goto F1; // 实际上是构成循环
        else
            fclose(fp);
        break;
    }
    case '2':
    {
        int find, repeat;
        long pos;
        char xz[8], ch[30], num[10];
        FILE *fp;
        CourseTab t, x;
        if ((fp = fopen("8888COUR.dat", "r+b")) == 0)
        {
            printf("\n\nCannot open COURSE data file!\n");
            system("pause");
            break;
        }
    F2:
        system("cls");
        printf("\n\t\tPlease input Course's num:  ");
        gets(num);
        find = 0;
        rewind(fp);
        pos = ftell(fp);
        while (fread(&t, sizeof(CourseTab), 1, fp))
        {
            if (!feof(fp) && strcmp(t.coursenum, num) == 0)
            {
                find = 1;
                break; // 结束查找
            }
            pos = ftell(fp);
        }
        if (find)
        {
        F21:
            system("cls");
            printf("\n\n==================================================");
            printf("\n Coursenum :      %-s", t.coursenum);
            printf("\n Couresename :     %-s", t.coursename);
            printf("\n Credit :      %-d", t.credit);
            printf("\n Coursehour : %-d", t.coursehour);
            printf("\n Teachername :    %-s", t.teachername);
            printf("\n==================================================");
            printf("\n\n New Coursenum : ");
            gets(ch); // 输入一个修改后的学号到字符数组ch
            if (strlen(ch) > 0 && strcmp(num, ch) != 0)
            {
                repeat = 0;
                rewind(fp); // 复位到学生文件头
                while (fread(&x, sizeof(CourseTab), 1, fp))
                { // 判断新输入的学号ch是否在学生文件中已经存在
                    if (strcmp(x.coursenum, ch) == 0)
                    { // 如果在学生文件中找到了给定学号ch的学生记录
                        repeat = 1;
                        break; // 结束查找
                    }
                }
                if (repeat)
                {
                    printf("\n\n\n\tThe Course %s has existed!  Continue modify? (y/n)  ", ch);
                    do
                    {
                        gets(ch);
                        if (ch[0] == 'y' || ch[0] == 'Y')
                            goto F21;
                        else
                        {
                            fclose(fp);
                            return;
                        }
                    } while (ch[0] != 'y' && ch[0] != 'Y' && ch[0] != 'n' && ch[0] != 'N');
                }
                strcpy(t.coursenum, ch); // 将学号ch字符串拷贝到学生结构体变量t的学号成员num
            }
            printf(" Coursename : ");
            gets(ch); // 继续修改学生的其他成员
            if (strlen(ch) > 0)
                strcpy(t.coursename, ch); // 如果输入了新的值，则更新学生结构体变量t的相应成员值
            printf(" Creadit : ");
            gets(ch);
            if (strlen(ch) > 0)
                t.credit = atoi(ch);
            printf(" Coursehour : ");
            gets(ch);
            if (strlen(ch) > 0)
                t.coursehour = atoi(ch);
            printf(" Teachername :");
            gets(ch);
            if (strlen(ch) > 0)
                strcpy(t.teachername, ch);
            printf("==================================================");
            fseek(fp, pos, SEEK_SET); // 在学生文件中定位正在修改的学生记录
            fwrite(&t, sizeof(CourseTab), 1, fp);
        }
        else
            printf("\n\n\n\t\tNo find record.\n");
        do
        {
            printf("\n\n\t\tModify another record? (y/n) ");
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y')
            goto F2; // 实际上是构成循环
        else
            fclose(fp);
        break;
    }
    case '3':
    {
        int find, repeat;
        long pos;
        char xz[8], ch[30], num[10];
        FILE *fp;
        ScoreTab t, x; // 定义学生表的结构体变量t, x
        if ((fp = fopen("8888SCOR.dat", "r+b")) == 0)
        {
            printf("\n\nCannot open SCORE data file!\n");
            system("pause");
            break;
        }
    F3:
        system("cls");
        printf("\n\t\tPlease input Student's num:  ");
        gets(num);
        find = 0;
        rewind(fp);
        pos = ftell(fp);
        while (fread(&t, sizeof(ScoreTab), 1, fp))
        {
            if (!feof(fp) && strcmp(t.num, num) == 0)
            {
                find = 1;
                break;
            }
            pos = ftell(fp); // 保留要读取的学生记录在学生文件中的位移量，以便重新定位该记录进行更新
        }
        if (find)
        { // 如果找到了给定学号num的学生记录，则进行修改
            system("cls");
            // 在屏幕上显示该学生记录的原来值
            printf("\n\n==================================================");
            printf("\n Num :      %-s", t.num);
            printf("\n Coursenum :     %-s", t.coursenum);
            printf("\n Normalscore :      %-d", t.normalscore);
            printf("\n Testscore : %d", t.testscore);
            printf("\n Score :    %-d", t.score);
            printf("\n==================================================");
            // 因为成绩与其余两项不同，所以不进行查重，直接进行修改数据
            printf("\nPlease Enter New Score : \n");
            printf("--------------------------------------------------");
            printf("\n Normalscore : ");
            gets(ch);
            if (strlen(ch) > 0)
                t.normalscore = atoi(ch);
            printf(" Testscore : ");
            gets(ch);
            if (strlen(ch) > 0)
                t.testscore = atoi(ch);
            printf(" Score :    ");
            gets(ch);
            if (strlen(ch) > 0)
                t.score = atoi(ch);
            printf("==================================================");
            fseek(fp, pos, SEEK_SET);
            fwrite(&t, sizeof(ScoreTab), 1, fp);
        }
        else
            printf("\n\n\n\t\tNo find record.\n");
        do
        {
            printf("\n\n\t\tModify another record? (y/n) ");
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y')
            goto F3; // 实际上是构成循环
        else
            fclose(fp);
        break;
        system("pause");
        break;
    }
    }
}

void TabShow()
{
    int num;
    system("cls");
    printf("\n\n                    0--return");
    printf("\n\n                    1--student infomation");
    printf("\n\n                    2--course infomation");
    printf("\n\n                    3--student score");
    printf("\n\n                    please choise: (0, 1, 2, 3): ");
    do
    {
        cin >> num;
    } while (num != 0 && num != 1 && num != 2 && num != 3);
    switch (num)
    {
    case 0:
        return;
    case 1:
    {
        int n = 0, flag;
        char ch[30];
        FILE *fp, *fpIdx;
        StudentTab t;
        StudentIdxTab tIdx;
        if ((fp = fopen("8888STUD.dat", "rb")) == 0)
        {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause");
            break;
        }
        if ((fpIdx = fopen("8888SIDX.dat", "rb")) == 0)
            flag = 0; // 这里我把学生和老师的索引分别创建了一个新的文件
        else
            flag = 1;
        if (flag)
        {
            while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'))
            {
                printf("\n-------------------------------------------------");
                printf("\n\tLogic sort using index file?(y/n): ");
                getchar();
                gets(ch);
            }
            if (ch[0] == 'n' || ch[0] == 'N')
                flag = 0;
        }
        system("cls");
        printf("\nnum         name          sex birthday    phone           counts  aver\n");
        printf("\n===============================================================================\n\n");
        if (flag)
        {
            fread(&tIdx, sizeof(StudentIdxTab), 1, fpIdx);
            while (!feof(fpIdx))
            {
                fseek(fp, tIdx.offset, SEEK_SET);
                fread(&t, sizeof(StudentTab), 1, fp);
                printf("%-10s  ", t.num);
                printf("%-12s  ", t.name);
                printf("%-2c  ", t.sex);
                printf("%4d-%2d-%2d  ", t.birthday.year, t.birthday.month, t.birthday.day);
                printf("%-15s ", t.phone);
                printf("%3d   ", t.counts);
                printf("%6.2f\n", t.aver);
                n++;
                fread(&tIdx, sizeof(StudentIdxTab), 1, fpIdx);
                if (n % 20 == 0 || feof(fpIdx))
                {
                    printf("\n===============================================================================\n\n");
                    printf("\t\t Press any key to continue. ");
                    getchar();
                    system("cls");
                    printf("\nnum         name          sex birthday    phone           counts  aver\n");
                    printf("\n===============================================================================\n\n");
                }
            }
        }
        else
        {
            fread(&t, sizeof(StudentTab), 1, fp);
            while (!feof(fp))
            {
                printf("%-10s  ", t.num);
                printf("%-12s  ", t.name);
                printf("%-2c  ", t.sex);
                printf("%4d-%2d-%2d  ", t.birthday.year, t.birthday.month, t.birthday.day);
                printf("%-15s ", t.phone);
                printf("%3d   ", t.counts);
                printf("%6.2f\n", t.aver);
                n++;
                fread(&t, sizeof(StudentTab), 1, fp);
                if (n % 20 == 0 || feof(fp))
                {
                    printf("\n===============================================================================\n\n");
                    printf("\t\t Press any key to continue. ");
                    getchar();
                    system("cls");
                    printf("\nnum         name          sex birthday    phone           counts  aver\n");
                    printf("\n===============================================================================\n\n");
                }
            }
        }
        if (n == 0)
        {
            printf("\n\t\t Not find record   ");
            system("pause");
            getchar();
        }
        fclose(fp);
        break;
    }
    case 2:
    {
        int n = 0, flag;
        char ch[30];
        FILE *fp, *fpIdx;
        CourseTab t;
        CourseIdxTab tIdx;
        if ((fp = fopen("8888COUR.dat", "rb")) == 0)
        {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause");
            break;
        }
        if ((fpIdx = fopen("8888CIDX.dat", "rb")) == 0)
            flag = 0;
        else
            flag = 1;
        if (flag)
        {
            do
            {
                printf("\n-------------------------------------------------");
                printf("\n\tLogic sort using index file?(y/n): ");
                getchar();
                gets(ch);
            } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
            if (ch[0] == 'n' || ch[0] == 'N')
                flag = 0;
        }
        system("cls");
        // 课程代码10 课程名称20 课程学分 课程学时 任课教师姓名12
        printf("\nnum        Coursename            credit     coursehour  teachername  \n");
        printf("\n=====================================================================\n\n");
        if (flag)
        {
            fread(&tIdx, sizeof(CourseIdxTab), 1, fpIdx);
            while (!feof(fpIdx))
            {
                fseek(fp, tIdx.offset, SEEK_SET);
                fread(&t, sizeof(CourseTab), 1, fp);
                printf("%-11s", t.coursenum);
                printf("%-21s", t.coursename);
                printf("%-11d", t.credit);
                printf("%-12d", t.coursehour);
                printf("%-13s", t.teachername);
                n++;
                fread(&tIdx, sizeof(CourseIdxTab), 1, fpIdx);
                if (n % 20 == 0 || feof(fpIdx))
                {
                    printf("\n\n=====================================================================\n\n");
                    printf("\t\t Press any key to continue. ");
                    getchar();
                    system("cls");
                    printf("\nnum        Coursename            credit     coursehour  teachername  \n");
                    printf("\n=====================================================================\n\n");
                }
            }
        }
        else
        {
            fread(&t, sizeof(CourseTab), 1, fp);
            while (!feof(fp))
            {
                printf("%-11s", t.coursenum);
                printf("%-21s", t.coursename);
                printf("%-11d", t.credit);
                printf("%-12d", t.coursehour);
                printf("%-13s", t.teachername);
                n++;
                fread(&t, sizeof(CourseTab), 1, fp);
                if (n % 20 == 0 || feof(fp))
                {
                    printf("\n\n=====================================================================\n\n");
                    printf("\t\t Press any key to continue. ");
                    getchar();
                    system("cls");
                    printf("\nnum        Coursename            credit     coursehour  teachername  \n");
                    printf("\n=====================================================================\n\n");
                }
            }
        }
        if (n == 0)
        {
            printf("\n\n\t\t Not find record   ");
            system("pause");
            getchar();
        }
        fclose(fp);
        break;
    }
    case 3:
    {
        int n = 0;
        char ch[30];
        FILE *fp1, *fp2, *fp3, *fp4, *fp5;
        StudentTab bt;
        CourseTab ct;
        ScoreTab st;
        if ((fp1 = fopen("8888STUD.dat", "rb")) == 0)
        {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause");
            break;
        }
        if ((fp2 = fopen("8888COUR.dat", "rb")) == 0)
        {
            printf("\n\nCannot open COURSE data file!\n");
            fclose(fp1);
            system("pause");
            break;
        }
        if ((fp3 = fopen("8888SCOR.dat", "rb")) == 0)
        {
            printf("\n\nCannot open SCORE data file!\n");
            fclose(fp1);
            fclose(fp2);
            system("pause");
            break;
        }
        if ((fp4 = fopen("8888SIDX.dat", "rb")) == 0)
        {
            printf("\n\nCannot open Student IDX file!\n");
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
            system("pause");
            break;
        }
        if ((fp5 = fopen("8888CIDX.dat", "rb")) == 0)
        {
            printf("\n\nCannot open Teacher IDX file!\n");
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
            fclose(fp4);
            system("pause");
            break;
        }
        printf("\nnum         name          courseNum   courseName            credit  score\n");
        printf("\n===============================================================================\n\n");
        while (fread(&st, sizeof(ScoreTab), 1, fp3))
        {
            // printf("%-12s",st.num);
            rewind(fp1);
            while (fread(&bt, sizeof(StudentTab), 1, fp1) == 1)
            {
                if (strcmp(st.num, bt.num) == 0)
                {
                    // printf("%-18s",bt.name);
                    break;
                }
            }
            printf("%-12s", st.coursenum);
            rewind(fp2);
            while (fread(&ct, sizeof(CourseTab), 1, fp2) == 1)
            {
                if (strcmp(st.coursenum, ct.coursenum) == 0)
                {
                    // printf("%-22s",ct.coursename);
                    // printf("%-8d",ct.credit);
                    break;
                }
            }
            n++;
            printf("%-12s", st.num);
            printf("%-18s", bt.name);
            printf("%s", st.coursenum);
            printf("%-22s", ct.coursename);
            printf("%-8d", ct.credit);
            printf("%-12d", st.score);

            if (n % 20 == 0)
            {
                printf("\n===============================================================================\n\n");
                printf("\t\t Press any key to continue. ");
                getchar();
                system("cls");
                printf("\nnum         name          courseNum   courseName            credit  score\n");
                printf("\n===============================================================================\n\n");
            }
        }
        if (n == 0)
        {
            printf("\n\n\t\t Not find record   ");
            system("pause");
        }
        else
        {
            printf("\n\n===============================================================================\n\n");
            system("pause");
        }
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        fclose(fp4);
        fclose(fp5);
        break;
    }
    }
}

void InitFile()
{ // 文件初始化
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    char ch;
    system("cls");
    printf("\n\n\tThe initialization of file will lose all data in data files!\n");
    while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
    {
        printf("\n\n\t\t\tContinue? (y/n)  ");
        cin >> ch;
    }
    if (ch == 'n' || ch == 'N')
        return;
    if ((fp1 = fopen("8888STUD.dat", "wb")) == 0)
    { // 初始化第1个文件。
        printf("\n\nCannot open STUDENT data file!\n");
        system("pause");
        exit(0);
    }
    if ((fp2 = fopen("8888COUR.dat", "wb")) == 0)
    { // 初始化第2个文件
        printf("\n\nCannot open COURSE data file!\n");
        system("pause");
        exit(0);
    }
    if ((fp3 = fopen("8888SCOR.dat", "wb")) == 0)
    { // 初始化第3个文件
        printf("\n\nCannot open SCORE data file!\n");
        system("pause");
        exit(0);
    }
    if ((fp4 = fopen("8888SIDX.dat", "wb")) == 0)
    { // 初始化第4个文件
        printf("\n\nCannot open Student Idx file!\n");
        system("pause");
        exit(0);
    }
    if ((fp5 = fopen("8888CIDX.dat", "wb")) == 0)
    { // 初始化第5个文件
        printf("\n\nCannot open Teacher Idx file!\n");
        system("pause");
        exit(0);
    }
    printf("\n\nInitialization success!\n");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    system("pause"); // 停下来，按任意键继续，让用户看屏幕上的提示信息
}

void InputData()
{
    int InputData_Choice;
    system("cls");
    printf("================================================================");
    printf("\n\n                    0--return");
    printf("\n\n                    1--student infomation");
    printf("\n\n                    2--course infomation");
    printf("\n\n                    3--student score");
    printf("\n================================================================");
    printf("\n\n\n                    Please choise: (0, 1, 2, 3): ");
    cin >> InputData_Choice;
    switch (InputData_Choice)
    {
    case 0:
        return;
    case 1:
    {
        char ch[30];
        int find;
        FILE *fp;
        StudentTab t, x;
        if ((fp = fopen("8888STUD.dat", "a+b")) == 0)
        {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause");
            break;
        }
    F1:
        system("cls");
        printf("\n\t\tInput Student Information ");
        printf("\n==================================================");
        printf("\n num : ");
        getchar();
        gets(ch);
        find = 0;
        rewind(fp);
        fread(&x, sizeof(StudentTab), 1, fp);
        while (!feof(fp))
        {
            if (strcmp(x.num, ch) == 0)
            {
                find = 1;
                break;
            }
            fread(&x, sizeof(StudentTab), 1, fp);
        }
        if (find)
        {
            printf("\n\n\n\t The student %s has existed !  Input next? (y/n)  ", ch);
            do
            {
                gets(ch);
            } while (ch[0] != 'y' && ch[0] != 'Y' && ch[0] != 'n' && ch[0] != 'N');
            if (ch[0] == 'y' || ch[0] == 'Y')
                goto F1;
            else
            {
                fclose(fp);
                return;
            }
        }
        strcpy(t.num, ch);
        printf(" name : ");
        gets(t.name);
        printf(" sex : ");
        gets(ch);
        t.sex = ch[0];
        printf(" birthday : year:  ");
        gets(ch);
        t.birthday.year = atoi(ch);
        printf("         month: ");
        gets(ch);
        t.birthday.month = atoi(ch);
        ;
        printf("         day:   ");
        gets(ch);
        t.birthday.day = atoi(ch);
        printf(" phone :");
        gets(t.phone);
        t.counts = 0;
        t.aver = 0.0;
        fwrite(&t, sizeof(StudentTab), 1, fp);
        printf("==================================================");
        printf("\n\n\n\t\t Input next? (y/n)  ");
        do
        {
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y')
            goto F1;
        else
            fclose(fp);
        break;
    }
    case 2:
    {
        char ch[10];
        char ch1;
        FILE *fp;
        CourseTab t, x;
        if ((fp = fopen("8888COUR.dat", "a+b")) == 0)
        {
            printf("\n\nCannot open COURSE data file!\n");
            system("pause");
            break;
        }
    F2:
        system("cls");
        fflush(stdin);
        printf("\n\tInput Course Information ");
        printf("\n================================================================");
        printf("\n           course num : ");
        scanf("%s", ch);
        getchar();
        rewind(fp);
        int find1 = 0;
        while (!feof(fp))
        {
            fread(&x, sizeof(CourseTab), 1, fp);
            if (strcmp(x.coursenum, ch) == 0)
            {
                find1 = 1;
            }
        }
        if (find1)
        {
            printf("\n\n\n================================================================\n\n");
            printf("     The course %s has existed !  Input next? (y/n)  ", ch);
            do
            {
                ch1 = getchar();
            } while (ch1 != 'y' && ch1 != 'Y' && ch1 != 'n' && ch1 != 'N');
            if (ch1 == 'y' || ch1 == 'Y')
                goto F2;
            else
            {
                fclose(fp);
                return;
            }
        }
        strcpy(t.coursenum, ch);
        char ch_coursename[20];
        int num_credit;
        int coursehour;
        char ch_teachername[12];
        printf("\nPlease Input Coursename:  ");
        gets(t.coursename);
        printf("Please Input Credit:  ");
        scanf("%d", &t.credit);
        printf("Please Input coursehour:  ");
        scanf("%d", &t.coursehour);
        getchar();
        printf("Please Input teachername:  ");
        gets(t.teachername);
        fwrite(&t, sizeof(CourseTab), 1, fp);
        printf("================================================================");
        printf("\n\n\n\t\t Input next? (y/n)  ");
        do
        {
            ch1 = getchar();
        } while (!(ch1 == 'y' || ch1 == 'n' || ch1 == 'Y' || ch1 == 'N'));
        if (ch1 == 'y' || ch1 == 'Y')
            goto F2;
        else
            fclose(fp);
        break;
    }
    case 3:
    {
        char ch[30];
        char num[10], coursenum[10];
        int find1 = 0, find2 = 0, find3 = 0;
        int score;
        FILE *fp1, *fp2, *fp3;
        StudentTab bt;
        CourseTab ct;
        ScoreTab st, t;
        if ((fp1 = fopen("8888STUD.dat", "rb")) == 0)
        {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause");
            break;
        }
        if ((fp2 = fopen("8888COUR.dat", "rb")) == 0)
        {
            printf("\n\nCannot open COURSE data file!\n");
            fclose(fp1);
            system("pause");
            break;
        }
        if ((fp3 = fopen("8888SCOR.dat", "a+b")) == 0)
        {
            printf("\n\nCannot open SCORE data file!\n");
            fclose(fp1);
            fclose(fp2);
            system("pause");
            break;
        }
    F3:
        system("cls");
        printf("\n\t\tInput Score Information ");
        printf("\n================================================================");
        printf("\n\t student num : ");
        do
        {
            fflush(stdin);
            gets(num);
        } while (strlen(num) == 0);
        printf("\n\t course num : ");
        do
        {
            fflush(stdin);
            gets(coursenum);
        } while (strlen(coursenum) == 0);

        find1 = 0;
        rewind(fp1);
        while (fread(&bt, sizeof(StudentTab), 1, fp1) == 1)
        {
            if (strcmp(bt.num, num) == 0)
            {
                find1 = 1;
                break;
            }
        }
        find2 = 0;

        rewind(fp2);
        while (fread(&ct, sizeof(CourseTab), 1, fp2) == 1)
        {
            if (strcmp(ct.coursenum, coursenum) == 0)
            {
                find2 = 1;
                break;
            }
        }
        find3 = 0;
        rewind(fp3);
        while (fread(&st, sizeof(ScoreTab), 1, fp3) == 1)
        {
            if (strcmp(st.num, num) == 0)
            {
                find3 = 1;
                break;
            }
        }
        if (!find1 || !find2 || find3)
        {
            if (!find1)
                printf("\n\t The student num: %s has not existed, can not input score! ", st.num);
            if (!find2)
                printf("\n\t The course num: %s has not existed, can not input score! ", st.coursenum);
            if (find3)
                printf("\n\t The record of this student and course has existed, can not input score! ");
            printf("\n\n\n\t\t Input next? (y/n)? ");
            do
            {
                gets(ch);
            } while (ch[0] != 'y' && ch[0] != 'Y' && ch[0] != 'n' && ch[0] != 'N');
            if (ch[0] == 'y' || ch[0] == 'Y')
                goto F3;
            else
            {
                fclose(fp1);
                fclose(fp2);
                fclose(fp3);
                return;
            }
        }
        strcpy(t.num, num);
        strcpy(t.coursenum, coursenum);
        printf("\n\t     score : ");
        cin >> t.score;
        fwrite(&t, sizeof(ScoreTab), 1, fp3);
        printf("================================================================");
        printf("\n\n\n\t\t Input next? (y/n)  ");
        do
        {
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y')
            goto F3;
        else
        {
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
        }
        break;
    }
    }
}

int main()
{
Start:
    int choice;
    system("cls");
    printf("\n\n\t\tStudent Management System\n\n");
    printf("================================================================\n");
    printf("\n\t\t   ---0.Exit System\n");
    printf("\n--------------------------------------------------------------\n");
    printf("\n\t---1.Input Data\t\t---2.Modify Record\n");
    printf("\n\t---3.Find Record\t---4.Table show\n");
    printf("\n\t---5.Statistics Report\t---6.Auto computing\n");
    printf("\n\t---7.Data Sort\t\t---8.Build Index\n");
    printf("\n--------------------------------------------------------------\n");
    printf("\n\t\t---9.Initialization of File\n");
    printf("\n================================================================\n");
    printf("\n\t\tPlease choice: (0-9):");
    cin >> choice;
    switch (choice)
    {
    case 1:
        InputData();
        goto Start;
    case 2:
        ModiFile();
        goto Start;
        break;
    case 3:
        FindRec();
        goto Start;
        break;
    case 4:
        TabShow();
        goto Start;
        break;
    case 5:
        printf("5");
        break;
    case 6:
        AutoCompute();  // 自动计算每一个学生所选修课程的门数和加权平均成绩
        goto Start; 
        break;
    case 7:
        Sort();
        goto Start;
        break;
    case 8:
        printf("8");
        break;
    case 9:
        InitFile();
        goto Start;
        break;
    case 0:
        system("cls");
        printf("\n\n----------------------------------------------------------------");
        printf("\n\n\t\t用户输入关闭指令,系统关闭\n\n");
        printf("----------------------------------------------------------------");
        return 0;
    }
    return 0;
}