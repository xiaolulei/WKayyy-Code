#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int a[1001],m[1001],e[1001],sum[1001];
int main() {
    int N;
    int sum1=0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        scanf("%d%d%d",&a[i],&m[i],&e[i]);
        sum[i]=(a[i]+m[i]+e[i]);
    }

    for(int i=1;i<=N;i++) {
       for(int j=i+1;j<=N;j++){
            if(abs(a[i]-a[j])<=5&&abs(m[i]-m[j])<=5&&abs(e[i]-e[j])<=5&&abs(sum[i]-sum[j])<=10)
            {sum1++;}
                 
            }
       
    }
    printf("%d",sum1);
    return 0;

}