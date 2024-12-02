#include<stdio.h>
void erjinzhi(int n);
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        erjinzhi(i);
        printf("\n");
    }
    return 0;
}
void erjinzhi(int n){
    int remainer=n%2;
    if(n>=2){
        erjinzhi(n);
    }
    if(remainer<2){
        printf("%d",remainer);
    }
}