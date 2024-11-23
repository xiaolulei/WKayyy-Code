#include<stdio.h>
#include<string.h>
int bubbleup(int sum);
int bubbledown(int sum);
void blackhole(int num);
int main(){
    int num;
    scanf("%d",&num);
    blackhole(num);
    return 0;
}
void blackhole(int num){
    int count=0;
    while(num!=6174&&count<7){
        int down = bubbledown(num);
        int up = bubbleup(num);
        num = up - down;
        printf("%04d-%04d=%04d\n",up,down,num);
        count++;
    }
}
int bubbledown(int num){
    int len=4;
    int arr[4];
    arr[0]=num%10;
    arr[1]=(num/10)%10;
    arr[2]=(num/100)%10;
    arr[3]=(num/1000);
    int i,j,temp=0;
    for(i=0;i<len-1;i++){
        for(j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr[0]*1000+arr[1]*100+arr[2]*10+arr[3]*1;
}




int bubbleup(int num){
    int len=4;
    int arr[4];
    arr[0]=num%10;
    arr[1]=(num/10)%10;
    arr[2]=(num/100)%10;
    arr[3]=(num/1000);
    int i,j,temp=0;
    for(i=0;i<len-1;i++){
        for(j=0;j<len-1-i;j++){
            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr[0]*1000+arr[1]*100+arr[2]*10+arr[3]*1;
}
