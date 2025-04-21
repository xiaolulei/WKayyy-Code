#include<stdio.h>

int H[100001],W[100001];

int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int min(int a,int b){ 
    if(a>b) return b;
    else return a;
}

int main(){
    int N,L,sq=0;
    scanf("%d %d",&N,&L);
    for(int i=1;i<=N;i++)
    {
        scanf("%d %d",&H[i],&W[i]);
        sq+=H[i]*W[i];
    }
    int temp=sq/L;

    return 0;
}