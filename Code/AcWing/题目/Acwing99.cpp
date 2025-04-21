#include<iostream>

using namespace std;

int W[5010][5010];

int main()
{
    int N,R;
    cin >> N >> R;
    R =  min(5001,R);
    for(int i=1;i<=N;i++){
        int tempx,tempy,tempw;
        cin >> tempx >> tempy >> tempw;
        tempx++; tempy++;
        W[tempx][tempy]+=tempw;
        
    }
    for(int i=1;i<=5001;i++){
        for(int j=1;j<=5001;j++){
            W[i][j]+=W[i-1][j]+W[i][j-1]-W[i-1][j-1];
        }
    }
    
    int max_w=0;
    for(int i=R;i<=5001;i++){
        for(int j=R;j<=5001;j++){
            max_w=max(max_w,W[i][j]-W[i-R][j]-W[i][j-R]+W[i-R][j-R]);
        }
    }
    cout << max_w << endl ;

    return 0;
}