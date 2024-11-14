#include<stdio.h>
int main(){
    int i=100;
    int i1,i2,i3;
    int j=100;
    int j1,j2,j3;
    int s=100;
    int s1,s2,s3;
    for(;i<1000;i++){
        for(;j<1000;j++){
            for(;s<1000;s++){
                if(i*2==j&&j*2==s){
                    i1=i%10;
                    i2=i/10%10;
                    i3=i/100;
                    j1=j%10;
                    j2=j/10%10;
                    j3=j/100;
                    s1=s%10;
                    s2=s/10%10;
                    s3=s/100;
                    
                }
            }
        }
    }
    return 0;
}
