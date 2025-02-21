#include<stdio.h>
int t,t1,t2;
int fly(){
	int h,m,s;
	scanf("%d:%d:%d",&h,&m,&s);
	t1=h*3600+m*60+s;
	scanf("%d:%d:%d",&h,&m,&s);
	t2=h*3600+m*60+s;
	char c;
	while((c=getchar())!='\n'){
		if(c=='('){
			c=getchar();
			c=getchar();
			t2+=(c-'0')*86400;
		}
	}
	return t2-t1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		int ans=(fly()+fly())/2,a,b,c;
		a=ans/3600;
        ans%=3600;
        b=ans/60;ans%=60;
        c=ans;
		printf("%02d:%02d:%02d\n",a,b,c);
	}
	return 0;
}