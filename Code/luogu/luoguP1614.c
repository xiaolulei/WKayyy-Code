#include<stdio.h>
int num[4000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int j=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    int sum;
    int min=0;
    for(int i=1;i<=m;i++){
        min+=num[i];
    }
    for(int i=m;i<=n;i++){
        int sum;
        for(int j=i;j>=i-m+1;j--){
        sum+=num[i];
        }
        if(min>sum) min=sum;
    }
    printf("%d",min);
    return 0;
}