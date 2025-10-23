#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

const int N = 1e5 + 10;

string str;

int num[N], idx;
bool status;//status是用来检测/**/是否闭合          
stack<pair<char, int>> op; 
char unpair[N];           

map<char, int> pr{{'(', 1}, {')', 1}, 
                  {'[', 2}, {']', 2}, 
                  {'{', 3}, {'}', 3}};

int main()
{   
    int len;
    cin >> len;
    
    for(int line = 0 ; line < len ; line ++)
    {
        getline(cin, str); 
        for(int j = 0; j < str.length() ; j ++)
        {
            if(str[j] == '/' && j + 1 < str.length() && str[j + 1] == '/') 
                break;
            if(str[j] == '/' && j + 1 < str.length() && str[j + 1] == '*')
            {
                j += 2; 
                status = true;
                while(j + 1 < str.length())
                {
                    if(str[j] == '*' && str[j + 1] == '/')
                    {
                        j += 2;
                        status = false;
                        break;
                    }
                    j++;
                }
                continue;
            }
        
            if(status)
            {
                while(j + 1 < str.length())
                {
                    if(str[j] == '*' && str[j + 1] == '/')
                    status = false;
                    j ++;
                }
                break;
            }

            if(str[j] == '(' || str[j] == '{' || str[j] == '[') 
                op.push({str[j], j});
            
            if(str[j] == ')' || str[j] == '}' || str[j] == ']')
            {
                if(op.empty())
                {
                    num[idx] = j;
                    unpair[idx ++] = str[j];
                }
                else if(pr[op.top().first] == pr[str[j]])
                {
                    op.pop();
                }
                else
                {
                    num[idx] = op.top().second;
                    unpair[idx ++] = op.top().first;
                    op.pop();
                    num[idx] = j;
                    unpair[idx ++] = str[j];
                }
            }
        }
    }
    
    while(!op.empty())
    {
        num[idx] = op.top().second;
        unpair[idx ++] = op.top().first;
        op.pop();
    }
    
    for(int i = 0 ; i < idx ; i ++)
    {
        cout << num[i] << unpair[i] << endl;
    }
    
    if(idx == 0)
    {
        cout << "NO ERROR" << endl;
    }
    
    return 0;
}
