#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[1010]={0},b[1010]={0};
    a[1]=1;b[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=1000;j++){
            a[j]*=i;
        }
        for(int s=1;s<=1000;s++){
            if(a[s]>9){
                a[s+1]+=a[s]/10;
                a[s]%=10;
            }
        }
        for(int a1=1;a1<=1000;a1++){
            b[a1]+=a[a1];
            if(b[a1]>9){
                b[a1+1]+=b[a1]/10;
                b[a1]%=10;
            }
        }
    }
    int len;
    for(len=1000;len>0&&b[len]==0;len--);
    for(int i=len;i>0;i--){
        printf("%d",b[i]);
    }
    return 0;
}

