#include<stdio.h>
#include<stdlib.h>
int main(){
    int w,x,h;
    int V,v;//体积 减去的体积
    scanf("%d %d %d",&w,&x,&h);
    int x1,y1,z1,x2,y2,z2;
    V=w*x*h;
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
        int a=abs(x1-x2)+1;
        int b=abs(y1-y2)+1;
        int c=abs(z1-z2)+1;
        v=a*b*c;
        V-=v;
    }
    printf("%d",V);
    return 0;
}