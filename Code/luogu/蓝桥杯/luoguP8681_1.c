#include<stdio.h>

long long s[100005]={0};
int ans;

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        long long temp;
        scanf("%lld",&temp);
        s[i]=s[i-1]+temp;
    }
    int level=1,all_level=3,current_level=2,temp_level;
    long long max=s[1];
    int i=1;
    while(all_level<=N){
        long long sum=s[all_level]-s[all_level-current_level];
        level++;
        if(sum>max){
            max=sum;
            ans=level;
        }
        temp_level=all_level;
        current_level*=2;
        all_level+=current_level;
    }
    long long extra_sum;
    if(all_level>N&&s[N]-s[temp_level]>max){
        ans=++level;
    }
    printf("%d\n",ans);
    return 0;
}