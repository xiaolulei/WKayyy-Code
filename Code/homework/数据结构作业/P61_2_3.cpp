#include <iostream>

using namespace std;

const int N = 10;
//假设链表最大容量为20

typedef pair<int,int> PII;

PII A[N],B[N],C[N * 2];
int head = 0;

int main()
{
    for(int i = 0 ; i < 10 ; i ++)
    {
        int num;
        cin >> num;
        A[i].first = num;
        if(i < 9)
        A[i].second = i + 1;
        else
        A[i].second = -1;
    }

    for(int i = 10 ; i < 20 ; i ++)
    {
        int num;
        cin >> num;
        B[i].first = num;
        if(i < 19)
        B[i].second = i + 1;
        else
        B[i].second = -1;
    }
     
    int idxa = 0, idxb = 10,lidx;
    while(idxa < 10 && idxb < 20)
    {
        if(A[idxa].first != B[idxb].first && idxa != 9)
        {
            A[idxa-1].second = A[idxa].second;
        }
        else if(A[idxa].first != B[idxb].first)
        {
            A[idxa-1].second = -1;
        }
        else
        {
            idxb++;
        }
        idxa ++;
    }
    
    return 0;
}