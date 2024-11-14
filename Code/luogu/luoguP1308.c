#include<stdio.h>
#include<string.h>
char b[1000000];
int mian(){
    char a[20];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    int flag=-1;
    int sum=0;
    int len1=strlen(a);
    int len2=strlen(b);
    int i=1;
        for(int j=0;j<=len2-2;){
           if(a[0]==b[j]||a[0]==b[j]+32||a[0]==b[j]-32){
            while(i<=len1-2){
                if(a[i]==b[j]||a[i]==b[j]+32||a[i]==b[j]-32){
                    i++;
                    sum++;
                }
                else break;
            }
           }


        }
    

    return 0;
}