#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 100010 //为字符串和栈定义一个最大尺寸

char a_stack[N];
char str[N];
int a_top = -1;

void push(char c) 
{
    if (a_top < N - 1) 
    {
        a_top++;
        a_stack[a_top] = c;
    }
}

void pop() 
{
    if (a_top > -1) a_top--;
}

char top() 
{
    if (a_top > -1) return a_stack[a_top];
    return '\0'; 
}

int main()
{
    scanf("%s", str);
    int size = strlen(str);
    bool huiwen = true;
    for(int i = 0 ; i < size/2; i ++) push(str[i]);

    int start = (size % 2 == 1) ? size/2 + 1 : size/2;

    for(int i = start; i < size ; i ++)
    {
        if(top() != str[i])
        {
            huiwen = false;
            break;
        }
        pop();
    }

    if(huiwen)
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}