#include<stdio.h>

void bubble_sort(int a[],int len);

int main(){
    int sum1=0;
    int N,B;
    int sum = 0;
    scanf("%d%d",&N,&B);
    int a[N+1];

    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }

    bubble_sort(a,N);

    for(int i=N;i>0;i--){
        sum+=a[i];
        sum1++;
        if(sum>B) {
            printf("%d",sum1);
            break;
        }
    return 0;
}
}
void bubble_sort(int a[],int len) {
    for(int i=1;i<len-1;i++){
        for(int j=1;j<len-i-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}