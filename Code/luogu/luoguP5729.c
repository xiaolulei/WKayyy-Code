#include<stdio.h>
int a[200][200][200];
int main()
{
    int w,x,h;
    scanf("%d%d%d",&w,&x,&h);
    int q;
    scanf("%d",&q);
    while(q--){
        int x1,y1,z1,x2,y2,z2;
        scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                for(int s=z1;s<=z2;s++){
                    a[i][j][s]=1;
                }
            }
        }
    }
    int last=0;
    for(int i=1;i<=w;i++){
            for(int j=1;j<=x;j++){
                for(int s=1;s<=h;s++){
                    if(a[i][j][s]==0) last++;
                }
            }
        }
    printf("%d\n",last);
    return 0;
}