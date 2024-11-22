#include<stdio.h>
//编写最大公约数GCD函数
/*********Begin*********/
long long int GCD(int a,int b){
    while (b!= 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
/*********End**********/ 
int sum,flag=1;
    
//编写最小公倍数LCM函数
/*********Begin*********/
long long int LCM(int a,int b){
    long long int gcd = GCD(a, b);
    return (long long int)a * b / gcd;
}
/*********End**********/ 
int main(void)
{  
    /*********Begin*********/
    int a,b;
    scanf("%d%d",&a,&b);
    if(a<0||b<0) {
        printf("Input Error");
        return 0;
    }
    long long int sum1=GCD(a,b);
    long long int sum2=LCM(a,b);
    printf("%lld %lld\n",sum1,sum2);
    /*********End**********/ 
    return 0;
}