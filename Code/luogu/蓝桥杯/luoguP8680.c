#include<stdio.h>
int chaijie(int n);
int main()
{
    int n;
    int sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(chaijie(i)){
            sum+=i;
        }
        else continue;
    }
    printf("%d",sum);
    return 0;
}
int chaijie(int n){
    while(n>0){
        int temp=n%10;
        if(temp==2||temp==1||temp==0||temp==9){
            return 1;
        }
        n/=10;
    }
    return 0;
}
