#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "prog.h"
int main() {
    char xz[8];
    while (1) {
        system("cls");
        printf("\n\n\t\t\tStudent Management System");
        printf("\n\n\t===========================================================");
        printf("\n\n\t\t\t\t0----Exit");
        printf("\n\n\t\t-------------------------------------------");
        printf("\n\n\t\t1----Input Data");
        printf("\t\t2----Modify Record");
        printf("\n\n\t\t3----Find Record");
        printf("\t4----Table Show");
        printf("\n\n\t\t5----Statistics Report");
        printf("\t6----Auto Computing");
        printf("\n\n\t\t7----Data Sort");
        printf("\t\t8----Build Index");
        printf("\n\n\t\t-------------------------------------------");
        printf("\n\n\t\t\t9----Initialization of File ");
        printf("\n\n\t===========================================================");
        printf("\n\n\t\t\tPlease choise: (0-9):");
        while (1) {
            gets(xz);
            if (xz[0] >= 48 && xz[0] <= 57) break;
        }
        system("cls");      
        switch (xz[0]) {
        case '0': return 0;
        case '1': InputData(); break;
        case '2': ModiFile(); break;
        case '3': FindRec(); break;
        case '4': TabShow(); break;
        case '5': StatRepo(); break;
        case '6': AutoComp(); break;
        case '7': Sort(); break;
        case '8': BuildIdx(); break;
        case '9': InitFile(); break;
        }
    }
}



/*-----------------------------------------------*/
void InputData() {    // ���ļ���׷�Ӽ�¼
    char xz[8];
    system("cls");
    printf("\n\n                    0--return");
    printf("\n\n                    1--student infomation");
    printf("\n\n                    2--course infomation");
    printf("\n\n                    3--student score");
    printf("\n\n\n                    Please choise: (0, 1, 2, 3): ");
    do {
        gets(xz);
    } while (xz[0] != '0' && xz[0] != '1' && xz[0] != '2' && xz[0] != '3');
    switch (xz[0]) {
    case '0': return;
    case '1': {  // ����ѧ��������Ϣ
        char ch[30];   int find;    FILE* fp;
        StudentTab t, x;      // ����ѧ�����Ľṹ�����t, x
        if ((fp = fopen("8888STUD.dat", "a+b")) == 0) {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause"); break;
        }
    F1: system("cls");
        printf("\n\t\tInput Student Information ");
        printf("\n==================================================");
        printf("\n num : ");    gets(ch);    // ����һ��ѧ�ŵ��ַ�����ch
        find = 0;
        rewind(fp);    // ��λ���ļ�ͷ
        //fread(&x, sizeof(StudentTab), 1, fp);    // ��ѧ���ļ��ж�ȡһ��ѧ����¼
        if (fread(&x, sizeof(StudentTab), 1, fp) != 1) break;  // ���Ӷ�ȡ�����ж�
        while (!feof(fp)) {  // �ж�ѧ��ch��ѧ����¼�Ƿ��Ѿ�����������������������
            if (strcmp(x.num, ch) == 0) {    // �����ѧ���ļ����ҵ���ѧ��ch��ѧ����¼�����������
                find = 1;    break;    // ��������
            }
            fread(&fp, sizeof(StudentTab), 1, fp);    // ��ѧ���ļ��ж�ȡһ��ѧ����¼
        }
        if (find) {    // ��ѧ���ļ����Ѿ����ڸ�ѧ�ŵ�ѧ����¼��ѡ���Ƿ�������һ��ѧ��
            printf("\n\n\n\t The student %s has existed !  Input next? (y/n)  ", ch);
            do {
                gets(ch);
            } while (ch[0] != 'y' && ch[0] != 'Y' && ch[0] != 'n' && ch[0] != 'N');
            if (ch[0] == 'y' || ch[0] == 'Y') goto F1;    // ʵ�����ǹ���ѭ��
            else { fclose(fp);  return; }
        }
        strcpy(t.num, ch);    // ��ѧ��ch�ַ���������ѧ���ṹ�����t��ѧ�ų�Աnum
        printf(" name : ");    gets(t.name);    // ���������ѧ����������Աֵ
        printf(" sex : ");    gets(ch);    t.sex = ch[0];
        printf(" birthday : year:  ");    gets(ch);    t.birthday.year = atoi(ch);
        printf("         month: ");    gets(ch);    t.birthday.month = atoi(ch);;
        printf("         day:   ");    gets(ch);    t.birthday.day = atoi(ch);
        printf(" phone :");    gets(t.phone);
        t.counts = 0;    t.aver = 0.0;
        fwrite(&t, sizeof(StudentTab), 1, fp);  // ��ѧ���ļ���׷��һ��ѧ����¼
        printf("==================================================");
        printf("\n\n\n\t\t Input next? (y/n)  ");
        do {
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y') goto F1;    // ʵ�����ǹ���ѭ��
        else fclose(fp);
        break;
    }
    case '2': {  // ����γ̻�����Ϣ
        char ch[30];   int find;    FILE* fp;
        CourseTab t, x;      // ����γ̱��Ľṹ�����t, x
        if ((fp = fopen("8888COUR.dat", "a+b")) == 0) {
            printf("\n\nCannot open COURSE data file!\n");
            system("pause"); break;
        }
    F2: system("cls");
        printf("\n\t\tInput Course Information ");
        printf("\n==================================================");
        printf("\n course num : ");    gets(ch);    // ����һ���γ̴��뵽�ַ�����ch
        find = 0;
        rewind(fp);    // ��λ���ļ�ͷ
        fread(&x, sizeof(CourseTab), 1, fp);    // �ӿγ��ļ��ж�ȡһ���γ̼�¼


        if (find) {    // ��ѧ���ļ����Ѿ����ڸÿγ̺ŵ�ѧ����¼��ѡ���Ƿ�������һ��ѧ��
            printf("\n\n\n\t The course %s has existed !  Input next? (y/n)  ", ch);
            do {
                gets(ch);
            } while (ch[0] != 'y' && ch[0] != 'Y' && ch[0] != 'n' && ch[0] != 'N');
            if (ch[0] == 'y' || ch[0] == 'Y') goto F1;    // ʵ�����ǹ���ѭ��
            else { fclose(fp);  return; }
        }
        strcpy(t.coursenum, ch);
        printf(" cousename : "); gets(t.coursename); // ����ƴд
        printf(" teachername : "); gets(t.teachername);
        t.credit = 0; t.coursehour = 0.0;
        fwrite(&t, sizeof(CourseTab), 1, fp);
        printf("==================================================");
        printf("\n\n\n\t\t Input next? (y/n) ");
        do {
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y') goto F2;    // ʵ�����ǹ���ѭ��
        else fclose(fp);
        break;



        printf("==================================================");
        printf("\n\n\n\t\t Input next? (y/n)  ");
        do {
            gets(ch);
        } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
        if (ch[0] == 'y' || ch[0] == 'Y') goto F2;    // ʵ�����ǹ���ѭ��
        else fclose(fp);
        break;
    }
    case '3': {
        char ch[30], num[10], coursenum[10];   int find1, find2, find3;
        FILE* fp1, * fp2, * fp3;
        StudentTab bt;      // ����ѧ�����Ľṹ�����bt
        CourseTab ct;      // ����γ̱��Ľṹ�����ct
        ScoreTab st;       // ����ɼ����Ľṹ�����st
        if ((fp1 = fopen("8888STUD.dat", "rb")) == 0) {
            printf("\n\nCannot open STUDENT data file!\n");
            system("pause"); break;
        }
        if ((fp2 = fopen("8888COUR.dat", "rb")) == 0) {
            printf("\n\nCannot open COURSE data file!\n");
            fclose(fp1);
            system("pause"); break;
        }
        if ((fp3 = fopen("8888SCOR.dat", "a+b")) == 0) {
            printf("\n\nCannot open SCORE data file!\n");
            fclose(fp1);    fclose(fp2);
            system("pause"); break;
        }
    F3: system("cls");
        printf("\n\t\tInput Score Information ");
        printf("\n==================================================");
        printf("\n\t student num : ");    gets(ch);    // ����һ��ѧ�ŵ��ַ�����ch
        if (strlen(num) == 0 || (strlen(ch) > 0 && strcmp(num, ch) != 0))
            strcpy(num, ch);    // ���������һ���µ�ѧ�ţ�����������ѧ���ַ�����num
        printf("\n\t course num : ");    gets(ch);    // ����һ���γ̴��뵽�ַ�����ch
        if (strlen(coursenum) == 0 || (strlen(ch) > 0 && strcmp(coursenum, ch) != 0))
            strcpy(coursenum, ch);    // ���������һ���µĿγ̴��룬�����������γ̴����ַ�����coursenum
        find1 = 0;
        system("pause");         rewind(fp1);    // ��λ��ѧ���ļ�ͷ
        fread(&bt, sizeof(StudentTab), 1, fp1);    // ��ѧ���ļ��ж�ȡһ��ѧ����¼
        while (!feof(fp1)) {  // �ж�ѧ��num��ѧ���Ƿ��Ѿ����ڣ���������������ɼ�
            if (strcmp(bt.num, num) == 0) {    // �����ѧ���ļ����ҵ��˸���ѧ��num��ѧ����¼�����������
                find1 = 1;    break;    // ��������
            }
            fread(&bt, sizeof(StudentTab), 1, fp1);    // ��ѧ���ļ��ж�ȡһ��ѧ����¼
        }
        find2 = 0;
        rewind(fp2);
        fread(&ct, sizeof(CourseTab), 1, fp2);
        while (!feof(fp2)) {
            if (strcmp(ct.coursenum, coursenum) == 0) {
                find2 = 1;  break;
            }
            fread(&ct, sizeof(CourseTab), 1, fp2);
        }
        find3 = 0;
        rewind(fp3);
        fread(&st, sizeof(CourseTab), 1, fp3);
        while (!feof(fp3)) {
            if (strcmp(ct.coursenum, coursenum) == 0) {
                find2 = 1;  break;
            }
            fread(&st, sizeof(CourseTab), 1, fp3);



            if (!find1 || !find2 || find3) {   // ����������ɼ������
                if (!find1)    // ѧ��num��ѧ�����в����ڣ���������ɼ�
                    printf("\n\t The student�� num: %s has not existed, can not input score! ", num);
                if (!find2)    // �γ̴���coursenum�ڿγ̱��в����ڣ���������ɼ�
                    printf("\n\t The course�� num: %s has not existed, can not input score! ", coursenum);
                if (find3)    // �ɼ������Ѿ�����ѧ��num�Ϳγ̴���coursenum�ĳɼ���¼
                    printf("\n\t The record of this student and course has existed, can not input score! ");
                printf("\n\n\n\t\t Input next? (y/n)? ");
                do {
                    gets(ch);
                } while (ch[0] != 'y' && ch[0] != 'Y' && ch[0] != 'n' && ch[0] != 'N');
                if (ch[0] == 'y' || ch[0] == 'Y') goto F3;    // ʵ�����ǹ���ѭ��
                else { fclose(fp1);    fclose(fp2);    fclose(fp3);    return; }
            }
            strcpy(st.num, num);    // ��ѧ��num�ַ����������ɼ��ṹ�����st��ѧ�ų�Ա
            strcpy(st.coursenum, coursenum);    // ���γ̴���coursenum�ַ����������ɼ��ṹ�����st�Ŀγ̴����Ա
            printf("\n\t     score : ");    gets(ch);    st.score = atoi(ch);    // �����ѧ�����ÿγ̵ĳɼ�
            fwrite(&st, sizeof(ScoreTab), 1, fp3);  // ��ɼ��ļ���׷��һ���ɼ���¼
            printf("==================================================");
            printf("\n\n\n\t\t Input next? (y/n)  ");
            do {
                gets(ch);
            } while (!(ch[0] == 'y' || ch[0] == 'n' || ch[0] == 'Y' || ch[0] == 'N'));
            if (ch[0] == 'y' || ch[0] == 'Y') goto F3;    // ʵ�����ǹ���ѭ��
            else { fclose(fp1);    fclose(fp2);    fclose(fp3); }
            break;
        }
    }
    }
}