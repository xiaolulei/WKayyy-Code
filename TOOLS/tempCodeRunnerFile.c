#include <stdio.h>
int a[8],sum[1000]={0};
int b[1000][7];
int main(){
    int n;
    int te,yi,er,san,si,wu,liu;
    scanf("%d",&n);
    for(int i=1;i<=7;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=7;j++){
            scanf("%d",&b[i][j]);
            for(int k=1;k<=7;k++){
                if(b[i][j]==a[k])
                sum[i]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
    if(sum[i]==7) te++;
    if(sum[i]==6) yi++;
    if(sum[i]==5) er++;
    if(sum[i]==4) san++;
    if(sum[i]==3) si++;
    // bug修复：修改此处的判断条件，使得每个得分段的计数条件是互斥的
    if(sum[i]==2) wu++;
    if(sum[i]==1) liu++;
    } 
    printf("%d %d %d %d %d %d %d",te,yi,er,san,si,wu,liu);
    return 0;
}
