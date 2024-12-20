#include<stdio.h>
int how_many_peach(int n);
int main()
{
    int n;
    scanf("%d",&n);
    n-=1;
    int peach=1;
    while(n--){
        peach=how_many_peach(peach);
    }
    printf("%d",peach);
    return 0;
}
int how_many_peach(int n){
    n=(n+1)*2;
    return n;
}