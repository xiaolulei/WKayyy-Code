#include<stdio.h>
#include<string.h>

int num[100000];
int main()
{
    int N;
    scanf("%d",&N);
    int min=100000,max=0;
    int m,n;
    int temp;
    for (int i=0;i<N;i++) {
        while(scanf("%d",&temp)==1){
            if (temp<min) min=temp;
            if (temp>max) max=temp;
            num[temp]++;
        }
    }
    int flag1=0,flag2=0;
    for(int i=min;i<=max;i++){
        if(num[i]==0&&!flag1) 
        {
            m=i;
            flag1++;
        }
        if(num[i]==2&&!flag2) {
            n=i;
            flag2++;
        }
        if(flag1&&flag2){
            break;
        }
    }
    printf("%d %d",m,n);
    return 0;
}