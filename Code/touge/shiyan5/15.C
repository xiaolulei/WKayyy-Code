#include<stdio.h>
int jia(int a,int b);
int jian(int a,int b);
int cheng(int a,int b);
int chu(int a,int b);
int jiecheng(int a);
int quyu(int a,int b);
int main()
{
    int a,c;
    char b;
    while(scanf("%d",&a)==1){
        while(1){
            scanf("%c",&b);
            if(b==' ') continue;
            else break;
        }
        if(b!='!')
        scanf("%d",&c);
        int sum;
        if(b=='!'){
            sum=jiecheng(a);
        }
        if(b=='*'){
            sum=cheng(a,c);
        }
        if(b=='/'){
            if(c==0) {
                printf("error\n");
                continue;
            }
            sum=chu(a,c);
        }
        if(b=='+'){
            sum=jia(a,c);
        }
        if(b=='-'){
            sum=jian(a,c);
        }
        if(b=='%'){
            if(c==0){
                printf("error\n");
                continue;
            }
            sum=quyu(a,c);
        }  
        printf("%d\n",sum);
    }
    return 0;
}
int jia(int a,int b)
{
    int sum;
    sum=a+b;
    return sum;
}
int cheng(int a,int b)
{
    int sum;
    sum=a*b;
    return sum;
}
int jian(int a,int b)
{
    int sum;
    sum=a-b;
    return sum;
}
int chu(int a,int b){
    //te shu qing kuang
    int sum;
    sum=a/b;
    return sum;
}
int jiecheng(int a){
    int sum=1;
    for(int i=1;i<=a;i++){
        sum*=i;
    }
    return sum;
}
int quyu(int a,int b){
    int sum;
    sum=a%b;
    return sum;
}