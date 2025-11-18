#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100

//模拟cpp中的栈

typedef struct 
{
    int items[N];
    int top;
} intstack;

void init_int_stack(intstack *s) 
{
    s->top = -1;
}

void push_int(intstack *s, int value) 
{
    if(s->top == N - 1) 
    {
        printf("Error\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

int pop_int(intstack *s) 
{
    if(s->top == -1) 
    {
        printf("Error\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int top_int(intstack *s) 
{
    if(s->top == -1) 
    {
        printf("Error\n");
        exit(1);
    }
    return s->items[s->top];
}


typedef struct 
{
    char items[N];
    int top;
} charstack;

void init_char_stack(charstack *s) 
{
    s->top = -1;
}

void push_char(charstack *s, char value) 
{
    if(s->top == N - 1) 
    {
        printf("Error\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

char pop_char(charstack *s) 
{
    if(s->top == -1) 
    {
        printf("Error\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

char top_char(charstack *s) 
{
    if(s->top == -1) 
    {
        printf("Error\n");
        exit(1);
    }
    return s->items[s->top];
}

//替换map
int map(char op) 
{
    switch(op){
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '(': return 4;
        case ')': return 5;
        case '#': return 6;
        default:  return -1;
    }
}

char matrix[7][7] = 
{
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'<', '<', '<', '<', '<', '=', 'x'},
    {'>', '>', '>', '>', 'x', '>', '>'},
    {'<', '<', '<', '<', '<', 'x', '='}
};

intstack num;
charstack op;

void eval()
{
    int b = pop_int(&num);
    int a = pop_int(&num);
    char c = pop_char(&op);
    int res = 0;
    if (c == '+') res = a + b;
    else if(c == '-') res = a - b;
    else if(c == '*') res = a * b;
    else if(c == '/') res = a / b;
    push_int(&num, res);
}

int main(){
    char str[101];
    scanf("%100s", str);
    strcat(str, "#");

    init_int_stack(&num);
    init_char_stack(&op);
    push_char(&op, '#');

    for(int i = 0; i < strlen(str); ++i) 
    {
        char c = str[i];
        if(isdigit(c)) 
        {
            int x = 0, j = i;
            while(j < strlen(str) && isdigit(str[j])) 
            {
                x = x * 10 + (str[j] - '0');
                j++;
            }
            push_int(&num, x);
            i = j - 1;
        }else 
        {
            char top_op = top_char(&op);
            int row = map(top_op);
            int col = map(c);

            if(row == -1 || col == -1) 
            {
                printf("Error\n");
                return 0;
            }

            char rel = matrix[row][col];

            if(rel == '<') 
            {
                push_char(&op, c);
            }else if (rel == '=') 
            {
                pop_char(&op);
            }else if (rel == '>') 
            {
                eval();
                i--;
            }else 
            {
                printf("Error\n");
                return 0;
            }
        }
    }

    printf("%d\n", top_int(&num));
    return 0;
}