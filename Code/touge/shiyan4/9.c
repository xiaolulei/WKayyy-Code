#include<stdio.h>
int main(){
    int a;
    int b[100000];
    while(scanf("%d",&a)==1){
        int sum=0;
        if(a == 0) {
        printf("0\n");
        continue;
    }
        while(a>0){
        b[sum++] = a % 2; 
        a = a / 2; 
        }
        for (int i = sum - 1; i >= 0; i--) 
            printf("%d", b[i]);    
        printf("\n");
    }
    return 0;
}
    
