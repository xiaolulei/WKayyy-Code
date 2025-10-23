#include <iostream>
#include <string>

using namespace std;

typedef struct {
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
    cout << "Please enter the stackSize" << endl;
    int stackSize;
    scanf("%d",&stackSize);
    getchar();
    InitDblStack(&stack, stackSize);
    while(1)
    {
        string choice;
        cin >> choice;
        if(choice == "Push0")
        {
            int tmp;
            cin >> tmp;
            Push0(&stack, tmp);
        }
        else if(choice == "Push1")
        {
            int tmp;
            cin >> tmp;
            Push1(&stack, tmp);
        }
        else if(choice == "Pop0")
        {
            int val0;
            Pop0(&stack, &val0);
            printf("Stack0.top is %d\n", val0);
        }
        else if(choice == "Pop1")
        {
            int val1;
            Pop1(&stack, &val1);
            printf("Stack1.top is %d\n", val1);
        }
        else if(choice == "Exit")
        {
            free(stack.V);
            break;
        }
        else
        {
            printf("Invalid command! Use Push0/Push1/Pop0/Pop1/Exit\n");
        }
    }
    for(int i = 0 ; i < stackSize; i ++) cout << stack.V[i] << " ";
}