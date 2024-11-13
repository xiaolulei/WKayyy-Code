#include<stdio.h>
int main(){
	int sum,s;
	for(int i=2;i<=10000;i++){
		sum=1;
		for(int j=2;j<=sqrt(i);j++){
			if(i%j==0){
				sum+=j+i/j;
			}
			if(i=sqrt(i)*sqrt(i)){
				sum-=sqrt(i);
			}
			if(sum==i){
				printf("%d",sum);
			}
		}
	}
	return 0;
}