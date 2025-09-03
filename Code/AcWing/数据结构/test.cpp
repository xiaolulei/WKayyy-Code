#include <iostream>
#include <cstring>
#include <unordered_map>
#include <stack>

using namespace std;

stack<char> op;
stack<int> num;

void eval()
{
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top() ; op.pop();
    int tempsum = 0;
    if(c == '+') tempsum = a + b;
    else if(c == '-') tempsum = a - b;
    else if(c == '*') tempsum = a * b;
    else tempsum = a / b;
    num.push(tempsum);
}   


int main()
{
    unordered_map<char,int> pr{{'+',1},{'-',1},{'*',2},{'/',2}};
    string str;
    cin >> str;
    for(int i = 0 ; i < str.size() ; i ++)
    {
        auto a = str[i];
        if(isdigit(a))
        {
            int tempsum = 0 , j = i ; 
            while( j < str.size() && isdigit(str[j]))
            {
                tempsum = tempsum * 10 + str[j++] - '0';
            }
            i = j - 1;
            num.push(tempsum);
        }
        else if(a == '(') op.push(a);
        else if(a == ')')
        {
            while(op.top() != '(') eval();
            op.pop();
        } 
        else 
        {
            while(op.size() && op.top() != '(' && pr[op.top()] >= pr[a]) eval();
            op.push(a);
        }
    }
    while(op.size()) eval();
    cout << num.top() << endl ;
    return 0;
}