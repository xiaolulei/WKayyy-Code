#include<stdio.h>
double caculate_ave(double *p,int n);
int main()
{
    double score[100][100];
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%lf",&score[i][j]);
        }
    }   
    double max=0;
    for(int i=0;i<n;i++){
        double *p=&score[i][0];
        score[i][m]=caculate_ave(p,m);
        if(max<score[i][m]) max=score[i][m];
    }
    printf("%.2lf",max);
    return 0;
}
double caculate_ave(double *p,int n){
    double sum=0;
    int max=*p,min=*p;
    for(int i=0;i<n;i++){
        sum+=*(p+i);
        if(max<*(p+i)) max=*(p+i);
        if(min>*(p+i)) min=*(p+i);
    }
    sum=sum-max-min;
    return sum/(n-2);
}