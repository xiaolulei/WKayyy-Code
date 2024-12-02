#include<stdio.h>
int caculator(int);
int main()
{
    int n;
    scanf("%d",&n);
    int sum=caculator(n);
    printf("%d",sum);
    return 0;
}
int caculator(int n){
    if (n == 1) {
        return 1;
    }
    return n + caculator(n - 1);
}