#include<stdio.h>
int num[1010][1010];
int main()
{
    int M,N;
    int min,max;
    scanf("%d%d",&M,&N);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(i==0&&j==0){
               scanf("%d",&num[i][j]);
               min=num[i][j];
               max=num[i][j]; 
               continue;
            }
            scanf("%d",&num[i][j]);
            if(num[i][j]>max) max=num[i][j];
            if(num[i][j]<min) min=num[i][j];
        }
    }
    printf("%d\n",max-min);
    return 0;
}