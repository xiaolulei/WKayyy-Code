#include<iostream>
#include<vector>

using namespace std;

bool cmp(vector<int>&A,vector<int>&B){//if A>= B;
    if (A.size() != B.size()) return A.size() > B.size();
        for(int i=A.size()-1;i>=0;i--)
            if(A[i]!=B[i]) return A[i]-B[i];
    return true;
}

vector<int> sub(vector<int>&A,vector<int>&B){//以A比B大为标准
    vector<int> C;
    int t=0;
    for(int i=A.size()-1;i>=0;i--){
        t=A[i]-t;
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10);
        if(t<0) t=1;
        else t=0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    vector<int> A,B;
    string a,b;
    cin >> a >> b; 
    for(int i=A.size()-1;i>=0;i--) A.push_back(a[i]-'0');//将字符串转换为数组
    for(int i=B.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    
    vector<int> C;
    
    if(cmp(A,B)) C=sub(A,B);//比较是A,B的大小，判断正负
    else{
        C=sub(B,A);
        cout << '-';
    }
    for(int i=C.size();i>=0;i--){
        cout << C[i];
    }
    return 0;
}
