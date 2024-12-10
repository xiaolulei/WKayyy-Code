#include<stdio.h>
#include<string.h>
int main()
{
    int flag=0;
    char a[100];
    scanf("%[^\n]",a);
    getchar();
    char b[100];
    scanf("%[^\n]",b);
    int lena=strlen(a);
    int lenb=strlen(b);
    int count=0;
    for(int i=0;i<lena;i++){
        if(a[i]==b[0]){
            for(int j=1;j<lenb;j++){
                if(a[i+j]==b[j]){
                    flag=1;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag){
                printf("%d\n",i);
                count++;
            }
        }
    }
    if(count==0){
        printf("-1\n");
    }
    return 0;
}