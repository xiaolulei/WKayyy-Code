#include<stdio.h>
void sixteenjinzhi(int);
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        sixteenjinzhi(i);
        if(i!=b){
            printf(" ");
        }
    }
    return 0;
}
void sixteenjinzhi(int num) {
    int remainder=num%16;
    if (num >= 16) {
        sixteenjinzhi(num / 16);
    }
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", remainder - 10 + 'A');
    }
}
//1 2 3 4 5 6 7 8 9 A B C D E F