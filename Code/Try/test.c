#include<stdio.h>

int n,m;
int s[100010]={0};

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",temp);
        s[i]=s[i-1]+temp;
    }
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",s[l]-s[r-1]);
    }
    return 0;
}