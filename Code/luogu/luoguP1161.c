#include<stdio.h>
int lap[3000000];
int main()
{
    int max=0;
    int n;
    scanf("%d",&n);
    while(n--){
        double a;
        double t;
        scanf("%lf%lf",&a,&t);
        for(int i=1;i<=t;i++){
            if((int)(i*a)>max) max=(int)(i*a);
            if(lap[(int)(i*a)]==0){
                lap[(int)(i*a)]=1;  
                continue;
            }
            if(lap[(int)(i*a)]==1){
                lap[(int)(i*a)]=0;
                continue;
            }
        }
    }
    for(int i=1;i<=max;i++){
        if(lap[i]==1){
            printf("%d\n",i);
            return 0;
        }
    }
    
    return 0;
}