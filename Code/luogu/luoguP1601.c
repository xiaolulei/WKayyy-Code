#include<stdio.h>
#include<string.h>

int main()
{
    char a[505],b[505];
    int a1[505]={0},b1[505]={0},c[505]={0};
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    int lena=strlen(a);
    int lenb=strlen(b);
    for(int i=0;i<lena;i++){
        a1[lena-1-i]=a[i]-'0';
    }
    for(int i=0;i<lenb;i++){
        b1[lenb-1-i]=b[i]-'0';
    }
    int lenc;
    if(lena>lenb){
        lenc=lena+1;
    }
    else lenc=lenb+1;
    for(int i=0;i<lenc;i++){
        c[i]+=a1[i]+b1[i];
        c[i+1]=c[i]/10;
        c[i]%=10;
    }
    while(c[lenc]==0&&lenc>0) lenc--;
    for(int i=lenc;i>=0;i--){
        printf("%d",c[i]);
    }
    return 0;
}