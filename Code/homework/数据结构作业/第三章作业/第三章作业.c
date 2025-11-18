#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 100010

typedef struct 
{
    char c;
    int i;
    int linenum;
} Pair;

Pair op_stack[N];
int op_top = -1;

void push(char c, int i,int x)
{
    if (op_top < N - 1) 
    {
        op_top++;
        op_stack[op_top].c = c;
        op_stack[op_top].i = i;
        op_stack[op_top].linenum = x;
    }
}

void pop() 
{
    if (op_top > -1) op_top--;
}

Pair top() 
{
    return op_stack[op_top];
}

bool is_empty() 
{
    return op_top == -1;
}

int pr(char c) 
{
    switch (c) 
    {
        case '(': case ')': return 1;
        case '[': case ']': return 2;
        case '{': case '}': return 3;
        default: return 0;
    }
}

char str[N];
int num[N], idx;
bool status;  
char unpair[N];           
int linenum[N];

int main()
{   
    int len;
    scanf("%d", &len);
    getchar();

    idx = 0;
    status = false;
    
    for(int line = 1 ; line <= len ; line ++)
    {
        if (fgets(str, sizeof(str), stdin) == NULL) break;
        int str_len = strlen(str);
        for(int j = 0; j < str_len ; j ++)
        {
            if (status) 
            {
                if (j + 1 < str_len && str[j] == '*' && str[j + 1] == '/') 
                {
                    status = false;
                    j++;
                }
                continue;
            }
            if (j + 1 < str_len && str[j] == '/' && str[j + 1] == '/') 
            {
                break;
            }
            if (j + 1 < str_len && str[j] == '/' && str[j + 1] == '*') 
            {
                status = true;
                j++;
                continue;
            }
        
            if(str[j] == '(' || str[j] == '{' || str[j] == '[') 
            {
                push(str[j], j, line);
            }
            if(str[j] == ')' || str[j] == '}' || str[j] == ']')
            {
                if(is_empty())
                {
                    linenum[idx] = line;
                    num[idx] = j;
                    unpair[idx ++] = str[j];
                }
                else if(pr(top().c) == pr(str[j]))
                {
                    pop();
                }
                else
                {
                    num[idx] = top().i;
                    linenum[idx] = top().linenum;
                    unpair[idx ++] = top().c;
                    pop();
                    num[idx] = j;
                    linenum[idx] = line;
                    unpair[idx ++] = str[j];
                }
            }
        }
    }
    
    while(!is_empty())
    {
        Pair p = top();
        linenum[idx] = p.linenum;
        num[idx] = p.i;
        unpair[idx ++] = p.c;
        pop();
    }
    printf("\nlinenum  num  char\n");
    for(int i = 0 ; i < idx ; i ++) printf("%d  %d  %c\n", linenum[i] ,num[i], unpair[i]);
    if(idx == 0) printf("No Error\n");
    return 0;
}