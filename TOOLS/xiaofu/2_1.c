#include <stdio.h>
int main() {
    int sum=0;
    for(int i=100;i<=200;i++){
        if(i%7==0) sum+=i;
    }
    printf("%d",sum);
    return 0;
}