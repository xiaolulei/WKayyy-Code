#include<stdio.h>
#include<math.h>
int zhishu(int n);
int main()
{
    int n,m,p;
    scanf("%d",&n);
    for(int i=2;i<=sqrt(n);i++){
        if(zhishu(i)&&n%i==0){
            if(zhishu(n/i)){
                if(i>(n/i)){
                    printf("%d\n",i);
                }
                else printf("%d\n",n/i);
            }
            else continue;
        }
        else continue;
    }
    return 0;
}
int zhishu(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}