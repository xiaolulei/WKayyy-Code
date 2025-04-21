#include <stdio.h>
#include <limits.h>

#define int long long

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int min_v = 0;
    int max_v = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        
        int low = (a / (b + 1)) + 1;
        int high = a / b;
        
        min_v = max(min_v, low);
        max_v = min(max_v, high);
    }
    
    printf("%lld %lld\n", min_v, max_v);
    return 0;
}
/*#include<stdio.h>

#define int long long

int num[10003][2];

int main()
{
    int N,V;
    int max=0,min=100000;
    scanf("%lld",&N);
    int flag=1;
    for(int i=1;i<=N;i++){
        scanf("%d %d",&num[i][0],&num[i][1]);
        int temp=num[i][0]/num[i][1];
        if(num[i][0]%num[i][1]==0&&(temp<max||i==1)){
            max=temp;
            flag=0;
        }
        else if(temp>max&&flag){
            max=temp;
        }
        int temp1=max;
        while(1){
            temp1--;
            if(num[i][0]-temp1*num[i][1]<temp1){
                continue;
            }
            else {
                temp1++;
                break;
            }
        }
        min=temp1;
    }
    printf("%lld %lld\n",min,max);
    return 0;
}这就是一坨屎*/

