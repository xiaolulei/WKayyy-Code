#include<stdio.h>
int num[101];
void swap(int *,int *);
void sort(int s[],int );
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    sort(num,N);
    for(int i=0;i<N-1;i++){
        printf("%d ",num[i]);
    }
    printf("%d",num[N-1]);
    return 0;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int s[],int N){
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(s[i]>s[j]){
                int *s1=&s[i],*s2=&s[j];
                swap(s1,s2);
            }
        }
    }
}