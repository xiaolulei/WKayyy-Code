#include<stdio.h>
int lap[3000000];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        float a;
        int t;
        scanf("%f%d",&a,&t);
        for(int i=1;i<=t;i++){
            lap[(int)(i*a)]=1;
        }
    }
    return 0;
}