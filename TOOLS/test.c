#include<stdio.h>
int main(){
	char a;
	int flag=1;
	int word=0;
	while(a=getchar()!='\n'){
		if(a==' '){
			flag=1;
		}
		else {
			if(flag){
				word++;
				flag=0;
			}
		}
	}

	return 0;
}