#include<stdio.h>
#include<math.h>
int zhishu(int n);
int main()
{
    int L;
    scanf("%d",&L);
    int sum=0;
    int i=0;
    int j=2;
    for(j;sum<L;j++){
        if(zhishu(j)){
            if((sum+j)<=L){
            i++;
            sum+=j;
            printf("%d\n",j);
            }
            else{
                break;
            }
        }
    }
    printf("%d\n",i);
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