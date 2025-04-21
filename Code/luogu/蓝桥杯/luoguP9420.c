#include<stdio.h>
long long a[10000],tot=0,ans=0;
int main(){
    for (int i = 1; i <= 9; i++){
		a[++tot] = i;
	}
	for (int i = 10; i <= 99; i++){
		a[++tot] = i / 10;
		a[++tot] = i % 10;
	}
	for (int i = 100; i <= 999; i++){
		a[++tot] = i / 100;
		a[++tot] = i / 10 % 10;
		a[++tot] = i % 10;
	}
	for (int i = 1000; i <= 2023; i++){
		a[++tot] = i / 1000;
		a[++tot] = i / 100 % 10;
		a[++tot] = i / 10 % 10;
		a[++tot] = i % 10;
	}
    int flag2=0,flag3=0,flag4=0;
    for (long long i = 1; i <= tot; i++){
		if (a[i] == 2){
			for (long long j = i + 1; j <= tot; j++){
				if (a[j] == 0){
					for (long long k = j + 1; k <= tot; k++){
						if (a[k] == 2){
							for (long long l = k + 1; l <= tot; l++){
								if (a[l] == 3){
									ans++;
								}
							}
						}
					}
				}
			}
		}
	}
    printf("%lld\n",ans);
}



