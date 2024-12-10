#include<stdio.h>
int num[31][31];
int status[31][31];
int main()
{
    int N;
    int s=1;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            num[i][j]=s;
            status[i][j]=1;
            s++;
        }
    }
    return 0;
}\


// &