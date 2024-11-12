#include<stdio.h>
#include<math.h>

int a [26];
int main(){
    char b[110];
    gets(b);
    for(int i = 0;b[i];i++){
        a[ b[i] - 'a' ] ++;
    }
    int min = 101 , max = -1;
    for(int i = 0;i < 25;i++){
        if(a[i]>0){
            if(a[i]>max) max = a[i];
            if(a[i]<min) min = a[i];
        }
    }
    int t = max - min;
    int flag=0;
    if(t>2){
        for(int i=2;i < sqrt(t);i++){
            if(t%i==0){
                flag = 1;
                break;
            }
        }
    }
    if(flag||t==1||t==0){
        printf("No Answer\n0");
    }
    else{
        printf("Lucky Word\n%d",t);
    }
    return 0;
}