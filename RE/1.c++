#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main(){
    char a2[] = {2,2,3,4};
    unsigned int a[6] = {3746099070,550153460,3774025685,1548802262,2652626477,2230518816};
    unsigned int v5 = 0,v3 = 0,v4 = 0;
    for(int i = 0;i < 4;i += 2){
        v3 = a[i];
        v4 = a[i + 1];

        v5 = 0x458BCD42 * 64;
        for(int j = 0;j <= 63;j++){
            v4 -= (v3 + v5 + 20) ^ ((v3 << 6) + a2[2]) ^ ((v3 >> 9) + a2[3]) ^ 16;
            v3 -= (v4 + v5 + 11) ^ ((v4 << 6) + a2[0]) ^ ((v4 >> 9) + a2[1]) ^ 32;
            v5 -= 0x458BCD42;
        }
        a[i] = v3;
        a[i + 1] = v4;
    }
    for(int i = 0;i <= 5;i++){
        cout<<hex<<a[i];
    }
}