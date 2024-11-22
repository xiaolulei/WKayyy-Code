#include<stdio.h>

int main(){
    int k1,k2;
    int suma=0,sumb=0;
    scanf("%d%d",&k1,&k2);
    for(int i=k1;i<=k2;i++){
        int yu,sum1=0,sum2=0;
        int i_=i;
        yu=i_%2;
        i_/=2;
        if(yu==0) sum1++;
        if(yu==1) sum2++;
        if(sum2>sum1) suma++;
        else sumb++;
    }
    printf("%d %d\n",suma,sumb);
    return 0;
}//538 462
