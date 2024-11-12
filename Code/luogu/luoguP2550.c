#include <stdio.h>
int a[8]={0}, sum[1000]={0};
int b[1000][7]={0};

int main() {
    int n;
    int te=0, yi=0, er=0, san=0, si=0, wu=0, liu=0; 
    scanf("%d", &n);
    for(int i = 1; i <= 7; i++) {
        scanf("%d", &a[i]);
    }

    
    for(int i = 1; i <= n; i++) {
        int sum1 = 0; 
        for(int j = 1; j <= 7; j++) {
            scanf("%d", &b[i][j]);
            for(int k = 1; k <= 7; k++) {
                if(b[i][j] == a[k]) {
                    sum1++;
                }
            }
        }
        sum[i] = sum1;
    }

   
    for(int i = 1; i <= n; i++) {
        if(sum[i] == 7) te++;
        if(sum[i] == 6) yi++;
        if(sum[i] == 5) er++;
        if(sum[i] == 4) san++;
        if(sum[i] == 3) si++;
        if(sum[i] == 2) wu++;
        if(sum[i] == 1) liu++;
    }

    printf("%d %d %d %d %d %d %d", te, yi, er, san, si, wu, liu);
    return 0;
}