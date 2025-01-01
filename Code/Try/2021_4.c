#include<stdio.h>
int Prime(int N){
    int i,flag;
    flag=0;
    for(i=2;i<N;i++){
        if(N%i==0){
            flag=1;
            break;
        }
    }
    return flag;
}
int main()
{
    int m,n,i;
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++){
        if(!Prime(i))
            printf("%d\n",i);
    }
    return 0;
}