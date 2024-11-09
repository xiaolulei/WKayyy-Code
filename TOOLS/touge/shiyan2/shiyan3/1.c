    #include<stdio.h>
        int main(void)
        {  
        /*********Begin*********/
        int m,n;
        int sum1=0,sum2=0;
        scanf("%d%d",&m,&n);
        int max,min;
        if(m>n) {min=n;
        max=m;
        }
        else if(m<n) {min=m;
        max=n;
        }
        else{
            sum1=m,sum2=n;
            printf("最大公约数是:%d\n最小公倍数是:%d",sum1,sum2);
            return 0;
        }
        for(int i=1;i<=min;i++){
            if(m%i==0&&n%i==0) sum1=i;
        }
        if(max%min==0) sum2=max;
        else{
            for(int i=1;i<=(m*n);i++){
                if(i%m==0&&i%n==0){ sum2=i;
                break;
                }
            }
        }
        printf("最大公约数是:%d\n最小公倍数是:%d",sum1,sum2);
        /*********End**********/ 
        return 0;
        }
