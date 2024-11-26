#include<stdio.h>
int num[4000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    int min=0;
    for(int i=1;i<=m;i++){
        min+=num[i];
    }
    for(int i=m;i<=n;i++){
        int sum=0;
        for(int j=i;j>=i-m+1;j--){
        sum+=num[i];
        }
        //printf("\n%d\n",sum);
        if(min>sum) min=sum;
    }
    printf("%d",min);
    return 0;
}