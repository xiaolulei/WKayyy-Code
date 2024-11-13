#include<stdio.h>
int len(int a,int b,int sum);
int main(){
    int i;
    char a;
    int b,c;
    int flag;
    int sum=0;
    int result;
    scanf("%d",&i);
    getchar();
    for(int j=1;j<=i;j++){
        scanf("%c",&a);
        getchar();
        while(scanf("%d%d",&b,&c)==2){
            getchar();
            if(a=='a'){
                sum=sum+b+c;
                result = len(b,c,sum);
                printf("%d+%d=%d\n%d\n",b,c,sum,result);
                flag=1;
                sum=0;
                continue;
            }
            if(a=='c'){
                sum=b*c;
                result = len(b,c,sum);
                printf("%d*%d=%d\n%d\n",b,c,sum,result);
                flag=2;
                sum=0;
                continue;
            }
            if(a=='b'){
                sum=b-c;
                result = len(b,c,sum);
                printf("%d-%d=%d\n%d\n",b,c,sum,result);
                flag=3;
                sum=0;
                continue;
        }
        else{
            switch(flag){
            case 1:sum=sum+b+c;
                   result = len(b,c,sum);
                   printf("%d+%d=%d\n%d\n",b,c,sum,result);
                   break;
            case 2:sum=b*c;
                   result = len(b,c,sum);
                   printf("%d*%d=%d\n%d\n",b,c,sum,result);
                   break;
            case 3:sum=b-c;
                result = len(b,c,sum);
                printf("%d-%d=%d\n%d\n",b,c,sum,result);
            }
            flag=0;
            }
        }
    }
    return 0;
}


int len(int a,int b,int sum){
    int result=3;
    for(a;a/10;a/=10){
        result++;
    }
    for(b;b/10;b/=10){
        result++;
    }
    if(sum>0){
        for(sum;sum/10;sum/=10){
        result++;
        }
    }
    else if(sum<0){
        for(sum;sum/10;sum/=10){
        result++;
        }
        result++;
    }
    result+=2;
    return result;
}