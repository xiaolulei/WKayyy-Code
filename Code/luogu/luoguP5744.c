#include<stdio.h>
struct student{
    char name[20];
    int year;
    int grade;
};
int main()
{
    struct student s[6];
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char a[100];
        int len;
        for(len=0;;len++){
            scanf("%c",&a[len]);
            if(a[len]==' ') break;
        }
        for(int j=0;j<len;j++){
            s[i].name[j]=a[j];
        }
        s[i].name[len]='\0';
        int b,c;
        scanf(" %d %d",&b,&c);
        getchar();
        s[i].year=b;
        s[i].grade=c;
    }
    for(int i=0;i<n;i++){
        printf("%s ",s[i].name);
        printf("%d ",s[i].year);
        printf("%d",s[i].grade);
        printf("\n");
    }
    return 0;
}