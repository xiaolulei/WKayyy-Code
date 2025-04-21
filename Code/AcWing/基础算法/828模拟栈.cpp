#include<iostream>

using namespace std;

const int N = 1e6;
int tt,num[N];

void judge_qurel(int tt){
    if(tt > 0) cout << num[ tt ] << endl ;
}

void judge_empty(int tt){
    if(tt > 0) cout << "NO" << endl;
    else cout << "YES" << endl ;
}

int main()
{
    int m;
    cin >> m ;
    while(m--){
    string temp;
    int n;
    cin >> temp;
    if( temp == "push" ){
        cin >> n;
        num[ ++ tt ] = n;
    }
    else if( temp == "pop" ) num[ tt --] = 0;
    else if( temp == "query" ) judge_qurel(tt);
    else judge_empty(tt);
    }
    return 0;
}

