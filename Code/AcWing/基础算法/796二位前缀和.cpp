#include<iostream>

using namespace std;

const int N=1e4+10;
long long num[N][N];

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&num[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            num[i][j]+=num[i-1][j]+num[i][j-1]-num[i-1][j-1];
        }
    }
    for(int i=1;i<=q;i++){
        int tempx1,tempx2,tempy1,tempy2;
        scanf("%d %d %d %d",&tempy1,&tempx1,&tempy2,&tempx2);
        printf("%lld\n",num[tempy2][tempx2]-num[tempy2][tempx1-1]-num[tempy1-1][tempx2]+num[tempy1-1][tempx1-1]);
    }

    return 0;
}