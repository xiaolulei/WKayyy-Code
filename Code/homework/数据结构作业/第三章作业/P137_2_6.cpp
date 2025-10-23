#include <iostream>

using namespace std;

const int N = 1000;
typedef pair<int, int> PII;
PII num[N];

int tail, sum, idx;

void init_num() 
 {
    for (int i = 0; i < 19; i++) {
        num[i].first = -1;
        num[i].second = i + 1;
    }
    num[19].first = -1;
    num[19].second = 0;
    tail = -1;
    sum = 0;
    idx = 0;
}

void init() 
{
    if (tail == -1) return;
    
    int head = num[tail].second;
    int current = head;
    
    do {
        int next = num[current].second;
        num[current].first = -1;
        current = next;
    } while (current != head);
    
    tail = -1;
    sum = 0;
    idx = 0;
}

void IsEmpty() 
{
    if (tail == -1)
        cout << "IsEmpty" << endl;
    else
        cout << "NotEmpty" << endl;
}

int Push(int a) 
{
    if (sum == 20) 
    {
        cout << "The queue is full!" << endl;
        return 0;
    }
    
    int new_node = idx;
    idx = num[idx].second;
    
    num[new_node].first = a;
    
    if (tail == -1) 
    {
        num[new_node].second = new_node;
        tail = new_node;
    } else {
        int head = num[tail].second;
        num[tail].second = new_node;
        num[new_node].second = head;
        tail = new_node;
    }
    
    sum++;
    return 1;
}

int Pop() 
{
    if (tail == -1) 
    {
        cout << "The queue is empty!" << endl;
        return -1;
    }
    
    int head = num[tail].second;
    int data = num[head].first;

    if (head == tail) 
    {
        num[head].second = idx;
        idx = head;
        tail = -1;
    } else {
        int new_head = num[head].second;
        num[tail].second = new_head;
        num[head].second = idx;
        idx = head;
    }
    
    sum--;
    return data;
}

int main() 
{
    init_num();
    while (1) {
        string choice;
        cin >> choice;
        if (choice == "init") 
        {
            init();
        } else if (choice == "isempty") 
        {
            IsEmpty();
        } else if (choice == "Push") 
        {
            int a;
            cin >> a;
            Push(a);
        } else if (choice == "Pop") 
        {
            int val = Pop();
            if (val != -1) {
                cout << "Pop: " << val << endl;
            }
        } else if (choice == "exit") 
        {
            break;
        }
    }
    return 0;
}
