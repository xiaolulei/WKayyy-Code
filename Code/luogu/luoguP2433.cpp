#include<iostream>
#include<iomanip>
#include<cmath>
// 填上你觉得需要的其他头文件
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        int a=14;
		int classmate=0,refrigeration=0,all=0;
		classmate=a/4;
		refrigeration=a%4;
		all=a-refrigeration;
		cout << classmate << endl << all << endl << refrigeration;
    } else if (T == 4) {
        float classmate=0;
		classmate=500/3;
		cout << classmate << setprecision(6);
    } else if (T == 5) {
        int a=260,b=220;
		int time;
		time=(a+b)/32;
		cout << time;
    } else if (T == 6) {
        cout << sqrt(6*6+9*9);
    } else if (T == 7) {
        cout << "90" << endl;
		cout << "70" << endl;
		cout << "0" << endl;
    } else if (T == 8) {
        cout << 2*5*3.141593 << endl << (5*5)*3.141593 << endl << (4/3)*3.141593*5*5*5;
    } else if (T == 9) {
        
    } else if (T == 10) {
        // 请自行完成问题 10 的代码
    } else if (T == 11) {
        // 请自行完成问题 11 的代码
    } else if (T == 12) {
        // 请自行完成问题 12 的代码
    } else if (T == 13) {
        // 请自行完成问题 13 的代码
    } else if (T == 14) {
        // 请自行完成问题 14 的代码
    }
    return 0;
}