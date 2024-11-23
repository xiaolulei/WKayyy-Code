#include<stdio.h>
#include<string.h>
int main(){
    int N;
    int sum=0;
    int i;
    scanf("%d",&N);
    for(i=1;;i++){
        int flag=0;
        char a[10];
        char b[10];
        int temp1=i,temp2=sum;
        sum=i*i;
        int len1,len2;
        int temp3=i,temp4=sum;
        for(len1=1;temp3/10;len1++){
            temp3/=10;
        }
        for(len2=1;temp4/10;len2++){
            temp4/=10;
        }
        for(int j=0;j<=len1;j++){
            a[j]=temp1%10;
            temp1/=10;
        }
        for(int j=0;j<=len2;j++){
            b[j]=temp2%10;
            temp2/=10;
        }
        int count=0;
        for(int s=0;s<=len1-1;s++){
            for(int j=len2;j>=len2-len1;j--){
                if(a[s]==b[j]){
                    count++;
                    printf("%c%c\n",a[s],b[j]);
                }
                if(count==len1&&i*i>1000){
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
    if(flag) break;
    } 
    printf("%d\n",i*i);
    return 0;
}