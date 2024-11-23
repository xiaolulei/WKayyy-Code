//亲密数
#include<stdio.h>
int main(){
    int A,sum1=0,sum2=0;
    scanf("%d",&A);
    for(int i=1;i<A;i++){
        if(A%i==0){
            sum1+=i;
            
        }
    }
    for(int i=1;i<sum1;i++){
        if(sum1%i==0){
            sum2+=i;
        }
    }
    if(sum2==A){
        printf("%d",sum1);
    }
    else printf("-1");
    return 0;
}