#include<stdio.h>
int main()
{
    long long a,b,n;
    scanf("%lld%lld%lld",&a,&b,&n);
    long long all=0,day=0,flag=1;;
    long long week=n/(a*5+b*2);
    n=n%(a*5+b*2);
    while(all<n){
        for(int i=1;i<=5;i++){
            all+=a;day++;
            if(all>=n){
                flag=0;
                break;
            }
        }
        if(!flag){
            break;
        }
        for(int i=1;i<=2;i++){
            all+=b;day++;
            if(all>=n){
                flag=0;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    day+=week*7;
    printf("%lld",day);
    return 0;
}