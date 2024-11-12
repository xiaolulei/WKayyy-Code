 #include<stdio.h>
    int main(){
        int a[2]={0};
        for(int i=0;i<=1;i++){
            scanf("%d%d",&a[0],&a[1]);
        }
         for(int i=1;i>=0;i--){
            printf("%d",a[i]);
        }
    }