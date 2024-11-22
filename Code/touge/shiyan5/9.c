#include<stdio.h>
#include<math.h>
int sushu(int M);
int sushu_x(int M);
int sushu_s(int M);
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int M;
        scanf("%d",&M);
        if(M==1){
            printf("%d 0\n",M);
            continue;
        }
        int debug=sushu(M);
        if(debug) {
            printf("%d 0\n",M);
            continue;
        }
        int x=sushu_x(M);
        int s=sushu_s(M);
        int long1=M-x;
        int long2=s-M;
        if(long1>long2)printf("%d %d\n",s,long2);
        else if(long1<long2)printf("%d %d\n",x,long1);
        else printf("%d %d\n",x,long2);
    }
    return 0;
}
int sushu_x(int M){
    for(int i=M-1;i>1;i--){
        int flag=1;
        for(int j=2;j<=sqrt(i);j++){
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if(flag){
            return i;
        }
    }
    return 0;
}
int sushu_s(int M){
    int i;
    for (i = M + 1;; i++) {
        int flag = 1;
        int j;
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return i;
        }
    }
}
int sushu(int M){
    int flag=1;
    for(int j=2;j <= sqrt(M);j++){
        if(M%j==0){
            flag=0;
            break;
        }
        
    }
    if(flag)
    return 1;
    return 0;
}
/*5
1000
120
500
256
365*/
/*997 3
113 7
499 1
257 1
367 2*/