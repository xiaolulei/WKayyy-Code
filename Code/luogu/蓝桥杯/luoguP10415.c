#include<stdio.h>
#include<math.h>
#define int long long

int gcd(int a,int b){
    int temp;
    while(b!=0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
    int a,b;
    scanf("%lld%lld",&a,&b);
    int temp=gcd(a,b);
    int len=2;
    if(temp==1){
            printf("0");
            return 0;
        }
    else{
        for(len;len<=sqrt(temp);len++){
            if(temp%len==0){
		        printf("%lld\n",(a/len)*(b/len));
				return 0;
			}
        }
        printf("%lld\n",(a/temp)*(b/temp));
    }
    return 0;
}