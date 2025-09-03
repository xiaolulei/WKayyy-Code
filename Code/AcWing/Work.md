# 基础算法笔记

## 基础算法

## 基本数据结构

### 单链表

单链表是用来存储图和树

每个节点存一个值和Next（下一个节点的指针），链表最后一个为空节点，下标为-1.

```cpp
#include <iostream>

using namespace std;

const int N = 1e6+10;

int e[N],ne[N],idx,m;
int head = -1;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点，也就是说当前能用什么节点

// 将x插到头结点
void add_to_head(int x)
{
    e [idx] = x , ne [idx] = head , head = idx ++;
}

// 将x插到下标是k的点后面
void add (int k ,int x)
{
    e [idx] = x , ne [idx] = ne [k] , ne [k] = idx++ ;
}

// 将下标是k的点后面的点删掉
void remove(int k)
{
    ne [ k ] = ne [ ne[k] ];
}

int main()
{
    cin >> m ;
    while(m--)
    {
        char str;
        int k,x;
        cin >> str ;
        if(str == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if(str == 'I')
        {
            cin >> k >> x;
            add( k - 1 , x);
        }
        else
        {
            cin >> k ;
            if (!k) head = ne[head];  // 1
            remove(k - 1);
        }
    }
    
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';  // 1
    cout << endl;
    return 0;
}
```

### 双链表

与单链表的区别就在于双链表可以指向上一个和下一个节点

```cpp
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m;
int l[N],r[N],e[N],idx;

void init()
{
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void insert (int k , int x)
{
    e[idx] = x;
    l[idx] = k , r[idx] = r[k] ;
    l[r[k]] = idx , r[k] = idx ++;
}

void remove(int k )
{
    r[l[k]] = r[k] ;
    l[r[k]] = l[k] ;
}

int main()
{
    init();
    cin >> m ;
    while(m--)
    {
        string op;
        int k , x;
        cin >> op;
        if(op == "L")
        {
            cin >> x;
            insert(0 , x);
        }
        else if(op == "R")
        {
            cin >> x ;
            insert(l[1] , x);
        }
        else if(op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1] , x);
        }
        else if(op == "IR")
        {
            cin >> k >> x;
            insert(k + 1 , x);
        }
        else
        {
            cin >> k;
            remove(k + 1);
        }
    }

    for(int i=r[0] ; i != 1 ; i = r[i]) cout << e[i] << ' ' ;
    cout << endl ;
    return 0;
}

```

### 模拟栈

先进后出即先插入的节点后弹出，像是你把东西一个一个存到罐子里但是取的时候是先取出罐子上方的东西也就是后进入的先弹出，等后边才能够取到下边的东西也就是先进后出。

```cpp
#include<iostream>

using namespace std;

const int N = 1e6;
int tt,num[N];

void judge_qurel(int tt){
    if(tt > 0) cout << num[ tt ] << endl ;
}

void judge_empty(int tt){
    if(tt > 0) cout << "NO" << endl;
    else cout << "YES" << endl ;
}

int main()
{
    int m;
    cin >> m ;
    while(m--){
    string temp;
    int n;
    cin >> temp;
    if( temp == "push" ){
        cin >> n;
        num[ ++ tt ] = n;
    }
    else if( temp == "pop" ) num[ tt --] = 0;
    else if( temp == "query" ) judge_qurel(tt);
    else judge_empty(tt);
    }
    return 0;
}

```

### 表达式运算

直接用中缀表达式进行计算

```cpp
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
```

中缀转后缀示意图
 
运算符栈我个人理解可以当算是一个给运算符缓冲的地方，真正计算的还得是后缀表达式地方

步骤       字符       运算符栈       后缀表达式
1          '3'        []             [3]
2          '+'        [+]            [3]
3          '4'        [+]            [3,4]
4          '*'        [+,*]          [3,4]
5          '2'        [+,*]          [3,4,2]
6          '-'        [+]            [3,4,2,*] → 弹出*（*优先级高于-）
                      [-]            [3,4,2,*,+] → 弹出+（+优先级等于-）
7          '('        [-,(]          [3,4,2,*,+]
8          '1'        [-,(]          [3,4,2,*,+,1]
9          '+'        [-,(,+]        [3,4,2,*,+,1]
10         '5'        [-,(,+]        [3,4,2,*,+,1,5]
11         ')'        [-]            [3,4,2,*,+,1,5,+] → 弹出+，直到遇到'('并弹出
12         结束       []             [3,4,2,*,+,1,5,+,-] → 弹出剩余的-

```CPP
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

// 中缀表达式转后缀表达式
vector<string> infixToPostfix(const string& infix) {
    vector<string> postfix;
    stack<char> opStack;
    unordered_map<char, int> priority{{'+',1}, {'-',1}, {'*',2}, {'/',2}};

    for (int i = 0; i < infix.size(); ++i) {
        char c = infix[i];
        if (isdigit(c)) {
            // 处理多位数
            string num;
            while (i < infix.size() && isdigit(infix[i])) {
                num += infix[i++];
            }
            --i; // 回退一位，避免跳过下一个字符
            postfix.push_back(num);
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            // 弹出到左括号为止
            while (opStack.top() != '(') {
                postfix.push_back(string(1, opStack.top()));
                opStack.pop();
            }
            opStack.pop(); // 弹出左括号
        } else { // 运算符
            while (!opStack.empty() && opStack.top() != '(' && 
                   priority[opStack.top()] >= priority[c]) {
                postfix.push_back(string(1, opStack.top()));
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    // 弹出剩余运算符
    while (!opStack.empty()) {
        postfix.push_back(string(1, opStack.top()));
        opStack.pop();
    }

    return postfix;
}

// 计算后缀表达式
int calculatePostfix(const vector<string>& postfix) {
    stack<int> numStack;
    for (const string& token : postfix) {
        if (isdigit(token[0])) {
            // 数字入栈
            numStack.push(stoi(token));
        } else {
            // 运算符：弹出两个数计算
            int b = numStack.top(); numStack.pop();
            int a = numStack.top(); numStack.pop();
            int res;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") res = a / b;
            numStack.push(res);
        }
    }
    return numStack.top();
}

int main() {
    string infix;
    cout << "输入中缀表达式（不含空格，支持+、-、*、/、()）：";
    cin >> infix;

    // 转换为后缀表达式
    vector<string> postfix = infixToPostfix(infix);
    cout << "后缀表达式：";
    for (const string& s : postfix) {
        cout << s << " ";
    }
    cout << endl;

    // 计算结果
    int result = calculatePostfix(postfix);
    cout << "计算结果：" << result << endl;

    return 0;
}

```

### 单调栈

经典问题：寻找某个数比当前数小且在其左边的数字在哪里

```cpp
#include <iostream>

using namespace std;

const int N = 1e5+10;

int num[N],n,tt;

int main()
{
    cin >> n ;
    while(n--)
    {
        int x;
        cin >> x;
        while(tt && num[tt] >= x) tt --;
        if(tt) cout << num[tt] << ' ';
        else cout << -1 << ' ';
        num[++ tt] = x;
    }
    return 0;
}

```