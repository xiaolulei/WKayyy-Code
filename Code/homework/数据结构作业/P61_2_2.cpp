#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11; 
const int M = 1e5 + 10;
//假定链表的数据不超过1e5;
//假定我们的两个链表的长度都为10

typedef pair<int,int> PII;

PII A[N],B[N],C[2 * N]; //我们解释C对A与B所有的数据进行排列
int idx[M];

int main() {
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        A[i].first = num;
        A[i].second = (i != 9) ? (i + 1) : -1;
        C[i] = {num, 0 * 10 + i};
    }

    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        B[i].first = num;
        B[i].second = (i != 9) ? (i + 1) : -1;
        C[10 + i] = {num, 1 * 10 + i};
    }

    sort(C, C + 20, [](const PII& a, const PII& b) {return a.first > b.first;});

    for (int i = 0; i < 19; i++) {
        int curr = C[i].second;
        int next = C[i + 1].second;

        int curr_arr = curr / 10;
        int curr_idx = curr % 10;
        int next_arr = next / 10;
        int next_idx = next % 10;

        if (curr_arr == 0) 
        {
            A[curr_idx].second = (next_arr == 0) ? (next_idx) : (10 + next_idx);
        } else 
        {
            B[curr_idx].second = (next_arr == 0) ? (next_idx) : (10 + next_idx);
        }
    }

    int last = C[19].second;
    int last_arr = last / 10;
    int last_idx = last % 10;
    if (last_arr == 0) 
    {
        A[last_idx].second = -1;
    } else {
        B[last_idx].second = -1;
    }

    cout << "合并结果：";
    int current = C[0].second;
    while (current != -1) {
        if (current < 10) {
            cout << A[current].first << " ";
            current = A[current].second;
        } else {
            cout << B[current - 10].first << " ";
            current = B[current - 10].second;
        }
    }

    return 0;
}
    