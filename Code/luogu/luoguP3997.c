#include<stdio.h>

int n;
long long s[100005]={0},max=0;

int main(){
    scanf("%d",&n);
    int flag=0;
    for(int i=1;i<=n;i++){
        long long temp;
        scanf("%lld",&temp);
        s[i]+=s[i-1]+temp;
        if(i>=2&&s[i]>=0){
            max+=s[i];
            flag=1;
        }
    }
    if(!flag){
        max=s[2];
    }
    printf("%lld\n",max);
    return 0;   
}