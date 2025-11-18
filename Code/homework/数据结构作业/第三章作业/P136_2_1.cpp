#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int top[2], bot[2]; 
    int *V;             
    int m;            
} DblStack;

void InitDblStack(DblStack *s, int size) 
{
    s->V = (int *)malloc(size * sizeof(int));
    if (s->V == NULL) 
    {
        printf("Error1\n");
        exit(1);
    }
    s->m = size;
    s->bot[0] = 0;
    s->top[0] = -1;
    s->bot[1] = size - 1;
    s->top[1] = size;
}

int IsEmpty0(DblStack *s) 
{
    return s->top[0] == -1;
}

int IsEmpty1(DblStack *s) 
{
    return s->top[1] == s->m;
}

int IsFull(DblStack *s) 
{
    return s->top[0] + 1 == s->top[1];
}

int Push0(DblStack *s, int e) 
{
    if (IsFull(s)) 
    {
        printf("The Stack is Full!\n");
        return 0;
    }
    s->top[0]++;
    s->V[s->top[0]] = e;
    return 1;
}

int Push1(DblStack *s, int e) 
{
    if (IsFull(s)) 
    {
        printf("The Stack is Full!\n");
        return 0;
    }
    s->top[1]--;
    s->V[s->top[1]] = e;
    return 1;
}

int Pop0(DblStack *s, int *e) 
{
    if (IsEmpty0(s)) 
    {
        printf("The Stack is Empty!\n");
        return 0;
    }
    *e = s->V[s->top[0]];
    s->top[0]--;
    return 1;
}

int Pop1(DblStack *s, int *e) 
{
    if (IsEmpty1(s)) 
    {
        printf("The Stack is Empty!\n");
        return 0;
    }
    *e = s->V[s->top[1]];
    s->top[1]++;
    return 1;
}

int main() {
    DblStack stack;
    printf("Please enter the stackSize\n");
    int stackSize;
    scanf("%d", &stackSize);
    getchar();
    InitDblStack(&stack, stackSize);

    while (1)
    {
        char choice[10];
        scanf("%s", choice); 
        if (strcmp(choice, "Push0") == 0)
        {
            int tmp;
            scanf("%d", &tmp);
            Push0(&stack, tmp);
        }
        else if (strcmp(choice, "Push1") == 0)
        {
            int tmp;
            scanf("%d", &tmp);
            Push1(&stack, tmp);
        }
        else if (strcmp(choice, "Pop0") == 0)
        {
            int val0;
            if (Pop0(&stack, &val0))
                printf("Stack0.top is %d\n", val0);
        }
        else if (strcmp(choice, "Pop1") == 0)
        {
            int val1;
            if (Pop1(&stack, &val1))
                printf("Stack1.top is %d\n", val1);
        }
        else if (strcmp(choice, "Exit") == 0)
        {
            free(stack.V);
            break;
        }
        else
        {
            printf("Invalid command! Use Push0/Push1/Pop0/Pop1/Exit\n");
        }
    }

    for (int i = 0; i < stackSize; i++)
        printf("%d ", stack.V[i]);
    return 0;
}