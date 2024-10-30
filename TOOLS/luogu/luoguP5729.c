#include<stdio.h>
#include<stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))  
#define max(a, b) ((a) > (b) ? (a) : (b)) 
int main(){
    int w,x,h;
    int axis[21][21][21]={0};
    scanf("%d %d %d",&w,&x,&h);
    int x1,y1,z1,x2,y2,z2;
    scanf("%d%d%d%d%d%d",x1,y1,z1,x2,y2,z2);
    for(int a=min(x1,x2);a<=max(x1,x2);a++){
        for(int b=min(y1,y2);b<=max(y1,y2);b++){
            for(int c=min(z1,z2);c<=max(z1,z2);c++){
                axis[a][b][c]=1;
            }
        }
    }
    int sum=0;
    for(int i=1; i<=w; i++){
        for(int j=1; j<=x; j++){
            for(int k=1; k<=h; k++){
                if(axis[i][j][k]==0){
                    sum++;
                }
            }
        }
    }
    printf("%d",sum);
    return 0;
}