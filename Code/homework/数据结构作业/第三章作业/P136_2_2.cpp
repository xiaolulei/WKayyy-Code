#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> a;

int main()
{
    string str;
    cin >> str;
    int size = str.size();
    bool isPalindrome = true;
    
    for(int i = 0 ; i < size/2; i ++) 
    {
        a.push(str[i]);
    }
    int start = (size % 2 == 1) ? size/2 + 1 : size/2;
    
    for(int i = start; i < size ; i ++)
    {
        if(a.top() != str[i])
        {
            isPalindrome = false;
            break;
        }
        a.pop();
    }
    
    if(isPalindrome)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
    