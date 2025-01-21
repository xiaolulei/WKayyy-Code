#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int max=0,min=10000;
    double sum=0;
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        sum+=temp;
        if(temp>max) max=temp;
        if(temp<min) min=temp; 
    }
    sum/=7.0;
    sum=(int)(sum*100.0+0.5)/100.0;
    printf("%d\n%d\n%.2lf\n",max,min,sum);
    return 0;
}