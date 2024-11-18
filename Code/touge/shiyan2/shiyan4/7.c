#include<stdio.h>
#include<math.h>
int gcd(int a,int b);
int main(){
    int a=0,b=0,c=0,d=0;
    char s[100];
    while(scanf("%d",&a)==1){
        scanf("%c",&s[0]);
        scanf("%d",&b);
        scanf("%c",&s[1]);
        scanf("%d",&c);
        scanf("%c",&s[2]);
        scanf("%d",&d);
        int sum1=0,sum2=0,sum3=0;
        if(a>0&&b<0){
            a*=-1;
            b*=-1;
        }
        if(a<0&&b<0){
            a*=-1;
            b*=-1;
        }
        if(c>0&&d<0){
            c*=-1;
            d*=-1;
        }
        if(c<0&&d<0){
            c*=-1;
            d*=-1;
        }
        if(b!=d){
            double temp3=fabs(b),temp4=fabs(d);
            a=a*temp4;
            c=c*temp3;
            b=b*temp4;
            d=d*temp3;
        }
        if(s[1]=='+'){
            sum1=a+c;
        }   
        if(s[1]=='-'){
            sum1=a-c;
        }
        sum2=gcd(sum1,b);
        if(sum2!=0){
            sum1/=sum2;
            b/=sum2;
        }
        if(sum1==0){
            printf("0\n");
            continue;
        }
        if(b==1){
            printf("%d\n",sum1);
            continue;
        }
        if(sum1/b!=1){
            if(b<0){
            sum1*=-1;
            b*=-1;
            }
            printf("%d/%d\n",sum1,b);
            }
        else if(sum1/b==1)  printf("1\n");
        else if(sum1/b==-1) printf("-1\n");
    }
    return 0;
}
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

/*      1/8--3/8
-1/-4--1/-2
1/3-1/3
1/3+2/3         */