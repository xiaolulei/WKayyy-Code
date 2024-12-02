#include <stdio.h>
void Rua();
int main() {
	Rua();//调用递归函数
	return 0;
}

void Rua() {
	/**********Begin**********/
    int num[100],sum=0;
    while((scanf("%d",&num[sum]))==1){
        sum++;
    }
    for(int i=sum-1;i>=0;i--){
        printf("%d\n",num[i]);
    }
	/**********End**********/
}