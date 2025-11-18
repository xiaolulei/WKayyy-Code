#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define N 1000010

//改用变量而不是定义为结构体，这样子的好处就是能少传点参数，相较于把定义结构体写在main函数中
//全局变量如果不按其意义命名很容易冲突
//或者说直接把变量定义扔main函树，传参给函数
int num_stack[N];
int num_top = -1; 

char op_stack[N];
int op_top = -1;

void num_push(int val) 
{
    if (num_top < N - 1) 
    {
        num_top++;
        num_stack[num_top] = val;
    }
}

int num_pop() 
{
    if (num_top > -1) 
    { 
        return num_stack[num_top--];
    }
    return 0;
}

int num_top_val() 
{
    if (num_top > -1) 
    {
        return num_stack[num_top];
    }
    return 0;
}
int num_size() 
{
    return num_top + 1;
}

void op_push(char val) 
{
    if (op_top < N - 1) 
    {
        op_top++;
        op_stack[op_top] = val;
    }
}
char op_pop() 
{
    if (op_top > -1)
    {
        return op_stack[op_top--];
    }
    return '\0';
}

char op_top_val() 
{
    if (op_top > -1) 
    {
        return op_stack[op_top];
    }
    return '\0';
}
int op_size() 
{
    return op_top + 1;
}

int f(char c) 
{
    switch (c) 
    {
        case '+': return 3;
        case '-': return 3;
        case '*': return 5;
        case '/': return 5;
        case '(': return 1;
        case ')': return 5;
        case '#': return 1;
        default: return 0;
    }
}

int g(char c) 
{
    switch (c) {
        case '+': return 2;
        case '-': return 2;
        case '*': return 4;
        case '/': return 4;
        case '(': return 6;
        case ')': return 1;
        case '#': return 1;
        default: return 0;
    }
}

void eval()
{
    int b = num_pop();
    int a = num_pop();
    char c = op_pop(); 
    int x = 0;
    if (c == '*') x = a * b;
    else if (c == '/') x = a / b;
    else if (c == '+') x = a + b;
    else x = a - b;
    num_push(x);
}

int main()
{
    char str[N]; 
    scanf("%s", str);
    
    int str_len = strlen(str);
    for(int i = 0; i < str_len; i++)
    {
        char c = str[i];
        if(isdigit(c))
        {
            int x = 0, j = i;
            while (j < str_len && isdigit(str[j])) 
            {
                x = x * 10 + (str[j] - '0');
                j++;
            }
            i = j - 1; 
            num_push(x);
        }
        else if (c == '(')
        {
            op_push(c);
        }
        else if (c == ')')
        {
            while (op_top_val() != '(') eval();
            op_pop();
        }
        else
        {
            while (op_size() > 0 && op_top_val() != '(' && f(op_top_val()) >=g(c))
                eval();
            op_push(c);
        }
    }
    
    while (op_size() > 0) eval();
    
    printf("%d\n", num_top_val());
    return 0;
}