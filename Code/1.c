#include<stdio.h>
int main(){
    int sum,count=0;
    for(int i=1;i<=10000;i++){
        sum = 0;
         for(int j=1;j<=i;j++){
            if(i%j==0) sum+=j;
         }
         if(i==sum){
            printf("%d",sum);
            count++;
         }
    }
    printf("%d",count);
    return 0;
}