#include<stdio.h>
#include<math.h>
int zhishu(int a);
int main()
{
    int n;
    int num[110];
    int sum=0,zs[110];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n;i++){
        if(num[i]==1){
            continue;
        }
        
        int temp=zhishu(num[i]);
        if(temp){
            zs[sum]=num[i];
            sum++;
        }
        else{
            continue;
        }
    }
    if(sum==0){
        return 0;
    }
    if(sum>2){
    for(int i=0;i<sum-1;i++){
        printf("%d ",zs[i]);
    }
    printf("%d",zs[sum-1]);
    }
    else{
        printf("%d",zs[0]);
    }
    return 0;
}
int zhishu(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return 0;
        else continue;
    }
    return 1;
}