#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define stacksize 200 // 元素最大数量，也就是栈的
#define N 100
#define M 100
#define maxlen 300 // 表达式最大长度

typedef struct 
{
    double items[stacksize];
    int top;
} stackdouble;

void init_double_stack(stackdouble* s) 
{
    s->top = -1;
}

void push_double(stackdouble* s, double value) 
{
    if (s->top >= stacksize - 1) 
    {
        printf("Error\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

double pop_double(stackdouble* s) 
{
    if (s->top < 0) {
        printf("Error\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

double top_double(const stackdouble* s) 
{
    if (s->top < 0) 
    {
        printf("Error\n");
        exit(1);
    }
    return s->items[s->top];
}

int size_double(const stackdouble* s) 
{
    return s->top + 1;
}

typedef struct 
{
    char items[stacksize];
    int top;
} stackchar;

void init_char_stack(stackchar* s) 
{
    s->top = -1;
}

void push_char(stackchar* s,char value) 
{
    if (s->top >= stacksize - 1) 
    {
        printf("Error\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

char pop_char(stackchar* s) 
{
    if (s->top < 0) 
    {
        printf("Error\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

char top_char(const stackchar* s) 
{
    if (s->top < 0) 
    {
        printf("Error\n");
        exit(1);
    }
    return s->items[s->top];
}

int size_char(const stackchar* s) 
{
    return s->top + 1;
}

typedef struct 
{
    char name[M];  
    double value;
} variable;

variable variables[N];
int variable_count = 0;

// 设置变量的值
void setvariable(const char* a, double b) 
{
    for(int i = 0; i < variable_count; ++i) 
    {
        if (strcmp(variables[i].name, a) == 0) 
        {
            variables[i].value = b;
            return;
        }
    }
    if(variable_count < N) 
    {
        strcpy(variables[variable_count].name, a);
        variables[variable_count].value = b;
        variable_count++;
    }else 
    {
        printf("Error\n");
    }
}

double getvariable(const char* a) 
{
    for(int i = 0; i < variable_count; ++i) 
    {
        if(strcmp(variables[i].name, a) == 0) 
        {
            return variables[i].value;
        }
    }
    printf("Error'%s'\n", a);
    return 0;
}

double getvalue(const char* a) 
{
    if (isalpha(a[0])) 
    {
        return getvariable(a);
    }
    return atof(a);
}

stackdouble numStack;
stackchar opStack;

void eval() 
{
    double b = pop_double(&numStack);
    double a;
    char op = pop_char(&opStack);
    if (op == '~') // '~' 代表一元负号
    {
        push_double(&numStack, -b);
        return;
    }
    a = pop_double(&numStack);
    double result = 0;
    if(op == '*') 
    {
        result = a * b;
    } else if(op == '/') 
    {
        result = a / b;
    } else if(op == '+') 
    {
        result = a + b;
    } else if(op == '-') 
    {
        result = a - b;
    } else if(op == '^') 
    {
        result = pow(a, b);
    }
    push_double(&numStack, result);
}

// 栈内符号的优先级
int f(char c) 
{
    switch (c) 
    {
        case '+': return 3;
        case '-': return 3;
        case '*': return 5;
        case '/': return 5;
        case '^': return 7;
        case '~': return 7;
        case '(': return 1;
        case ')': return 8;
        case '#': return 0;
        default: return 0;
    }
}

// 准备入栈的符号的优先级
int g(char c) 
{
    switch (c) {
        case '+': return 2;
        case '-': return 2;
        case '*': return 4;
        case '/': return 4;
        case '^': return 6;
        case '~': return 6;
        case '(': return 8;
        case ')': return 1;
        case '#': return 0;
        default: return 0;
    }
}


int main() 
{
    init_double_stack(&numStack);
    init_char_stack(&opStack);
    push_char(&opStack, '#');

    char str[maxlen];
    printf("Enter the biaodashi: \n");
    fgets(str, sizeof(str), stdin);
    strcat(str, "#");            

    int i = 0;
    while(i < strlen(str)) 
    {
        char c = str[i];
        if (c == ' ') 
        {
            i++;
            continue;
        }
        if (isdigit(c)||isalpha(c)) 
        {
            char words[M] = {0};
            int k = 0;
            while (i < strlen(str) && (isdigit(str[i])||isalpha(str[i])||str[i] == '.')) 
            {
                if (k < M - 1) words[k++] = str[i];
                i++;
            }
            
            while(i < strlen(str) && str[i] == ' ') i++;

            if (i < strlen(str) && str[i] == '=') 
            {
                i++;
                while(i < strlen(str) && str[i] == ' ') i++;
                char bianliang[M];
                strcpy(bianliang, words);
                char valueToken[M] = {0};
                k = 0;
                while (i < strlen(str) && (isdigit(str[i])||isalpha(str[i])||str[i] == '.')) 
                {
                    if (k < M - 1) 
                    {
                        valueToken[k++] = str[i];
                    }
                    i++;
                }
                setvariable(bianliang, getvalue(valueToken));
                continue;
            }
            push_double(&numStack, getvalue(words));
        } else
        {
            if (f(top_char(&opStack)) < g(c))
            {
                push_char(&opStack, c);
                i++;
            }
            else if (f(top_char(&opStack)) == g(c))
            {
                pop_char(&opStack);
                i++;
            }
            else
            {
                eval();
            }
        }
    }
    
    if (size_double(&numStack) > 0) 
    {
        printf("%f\n", top_double(&numStack));
    }

    return 0;
}