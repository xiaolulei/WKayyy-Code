#include<stdio.h>
int main()
{
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(int i=4,j=9;i>=0;i--,j--){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    for(int i=0;i<9;i++){
        printf("%d,",a[i]);
    }
    printf("%d\n",a[9]);
    return 0;
}