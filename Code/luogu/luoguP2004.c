#include<stdio.h>
long long a[1001][10001];
int n,m,c;
int main()
{
    scanf("%d %d %d",&n,&m,&c);
    for(int y=1;y<=n;y++)
        for(int x=1;x<=m;x++)
            scanf("%lld",&a[y][x]);
    
    for(int y=1;y<=n;y++)
        for(int x=1;x<=m;x++)
            a[y][x]+=a[y-1][x]+a[y][x-1]-a[y-1][x-1];

    int tempx=0,tempy=0;
    long long max=-2e18;
    for(int y=c;y<=n;y++){
        for(int x=c;x<=m;x++){
            long long sum=a[y][x]-a[y-c][x]-a[y][x-c]+a[y-c][x-c];
            if(sum>max){
                max=sum;
                tempx=x-c+1;
                tempy=y-c+1;
            }
        }
    }
    printf("%d %d\n",tempy,tempx);
    return 0;
}