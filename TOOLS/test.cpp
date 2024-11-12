#include<cstdio>
#include<cstring>
#include<string>//字符串头文件。
using namespace std;
int main()
{
	char a[7],b[7];//定义字符串。
	int ans1=1,ans2=1;//分别为两串的乘积。
	scanf("%s",a);
	scanf("%s",b);//读入。
	int n=strlen(a);
	int m=strlen(b);//strlen函数求长度。
	for(int i=0;i<n;i++){
		ans1*=(int)a[i]-64;
	}
	for(int i=0;i<m;i++){
		ans2*=(int)b[i]-64;//此处用到了ASCII码表和强制类型转换，不知道的同学看链接。
	}
	if(ans1 % 47==ans2 % 47) printf("GO");
	else printf("STAY");//判断后输出。
	return 0;//返回。
}