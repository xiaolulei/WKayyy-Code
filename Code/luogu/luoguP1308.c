#include<stdio.h>
#include<string.h>
char b[1000001];  
int position[10000];
int main()
{
    int count=0;
    char a[20];
    gets(a);
    gets(b);
    int lena=strlen(a);
    int lenb=strlen(b);
    int p=0;
    for(int i=0;i<lenb;i++)
    {
        int sum=0;
        for(int j=0;j<lena;j++){
            if(a[j]==b[i+j]||a[j]==b[i+j]+'a'-'A'||a[j]==b[i+j]+'A'-'a'){
                if((b[i-1]==' '&&b[i+lena]==' ')||(i==0&&b[i+lena]==' ')){
                    sum++;
                }
            }
        }
        if(sum==lena) {
            count++;
            position[p]=i;
            p++;
        }
    }
    if(count==0) printf("-1");
    else printf("%d %d",count,position[0]);
    return 0;
}