#include <stdio.h>
int reserve(int num);
int reserve1(int num);
int reverse(int num) {
    int a = 0;
    while (num > 0) {
        a=a*10+num%10;
        num/=10;
    }
    return a;
}
int reserve1(int num) {
    int a=1;
    while (num%10==0) {  
        a*=10;
        num/=10;
    }
    return reverse(num)*a;  
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int c=reserve1(a);
        int result=c*b;
        printf("%d\n", result);
    }
    return 0;
}