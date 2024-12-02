#include <stdio.h>
int main(){
char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char c;
int i=6;
for (int i=6;i<15;i++){
    c=b[i+10];
	b[i+10]=b[i];
	b[i++]=c;
}
printf("%s",b);
}

