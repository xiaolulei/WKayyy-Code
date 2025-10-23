#include <iostream>

using namespace std;

const int N = 1e5 + 10;

typedef pair<int,int> PII;

PII node[N];
int head = 1; //头指针
int tail = -1;

void initiate()
{
    for(int i = 1 ; i <= 19 ; i ++)
    {
        node[i].first =  i;
        node[i].second = i + 1;
    }
    node[20].first = 20;
    node[20].second = -1;
}


int main()
{

    initiate();

    int mink,maxk;
    cin >> mink >> maxk;
    int pre = 0,current = head;
    while(current != -1)
    {
        if(node[current].first < maxk && node[current].second > mink)
        {
            if(head == current) head = node[current].second;
            else
            {
                node[pre].second = node[current].second;
            }
        }
        pre = current;
        current = node[current].second;
    }

    current = head;
    while(current != -1)
    {
        cout << node[current].first << ' ';
        current = node[current].second;
    }
    return 0;
}