#include<stdio.h>
char a[102][102];
int b[102][102]={0};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%c",&a[i][j]);
            if(a[i][j]=='*'){
                b[i][j+1]+=1;
                b[i][j-1]+=1;
                b[i+1][j]+=1;
                b[i+1][j+1]=1;
                b[i+1][j-1]+=1;
                b[i-1][j]+=1;
                b[i-1][j+1]+=1;
                b[i-1][j-1]+=1; 
            }
        }
        getchar();
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!='*') printf("%d",b[i][j]);
            else printf("%c",'*');
        }
        printf("\n");
    }
    return 0;
}