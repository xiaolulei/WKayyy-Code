#include <iostream>

using namespace std;

const int m = 20; 
int Q[m];       
int front = 0;      
int rear = 0;      
int tag = 0;     

void Push(int a) 
{
    if (front == rear && tag == 1) 
    {
        cout << "The queue is full!" << endl;
        return;
    }
    Q[rear] = a;
    rear = (rear + 1) % m;
    if (front == rear) 
    {
        tag = 1;
    }
}

int Pop() 
{
    if (front == rear && tag == 0) 
    {
        cout << "The queue is empty!" << endl;
        return -1;
    }
    int data = Q[front];
    front = (front + 1) % m;  
    if (front == rear) 
    {
        tag = 0; 
    }
    return data;
}

int main() 
{
    while (1) 
    {
        string choice;
        cin >> choice;
        if (choice == "Push") 
        {
            int a;
            cin >> a;
            Push(a);
        } 
        else if (choice == "Pop") 
        {
            int val = Pop();
            if (val != -1) {
                cout << "Pop: " << val << endl;
            }
        } 
        else if (choice == "exit") 
        {
            break;
        }
    }
    return 0;
}
