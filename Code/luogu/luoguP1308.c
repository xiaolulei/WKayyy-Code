#include<stdio.h>
#include<string.h>
char b[1000001];
int main()
{
    int count=0;
    char a[20];
    gets(a);
    gets(b);
    int position[100];
    int lena=strlen(a);
    int lenb=strlen(b);
    int p=0;
    for(int i=0;i<lenb;i+=lena)
    {
        int sum=0;
        for(int j=0;j<lena;j++){
            if(a[j]==b[i+j]||a[j]==b[i+j]+'a'-'A'||a[j]==b[i+j]+'A'-'a'){
               sum++;
            }
        }
        if(sum==lena) {
            count++;
            position[p]=i;
        }
    }
    if(count==0) printf("-1");
    else printf("%d %d",count,position[0]);
    return 0;
}