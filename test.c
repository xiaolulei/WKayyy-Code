#include<stdio.h>
#define MOD 114
int panda(int n){
    if (n<3){
        return 1;
    }
    return (panda(n-1)+panda(n-4))%MOD;
}
int main(){
    int n;
    scanf("%d",&n);
    int result=panda(n);
    printf("%d\n",result);
    return 0;
}