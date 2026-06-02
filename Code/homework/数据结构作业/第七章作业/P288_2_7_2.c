#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node;

node* new_node(int value)
{
    node* temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->value = value;
    return temp;
}

void insert_node(int value,node** first_node,double* querry_success_num,double maxsize[])
{
    int idx = (3 * value) % 11;
    if(first_node[idx] == NULL)
    {
        first_node[idx] = new_node(value);
        (*querry_success_num)++;
        maxsize[idx] = maxsize[idx] > 1 ? maxsize[idx] : 1;
    }
    else
    {
        node* current = first_node[idx];
        int i = 1;
        while(current -> next != NULL)
        {
            current = current -> next;
            i++;
        }
        maxsize[idx] = i + 1;
        (*querry_success_num) += (i + 1);
        current->next = new_node(value);
    }
}



int main()
{
    node* first_node[11];
    double querry_success_num = 0,max_size[11];
    for(int i = 0 ; i < 11 ; i ++)
    {
        first_node[i] = NULL;
        max_size[i] = 0;
    }
    int inser_value[8] = {32,13,49,24,38,21,4,12};
    for(int i = 0 ; i < 8 ; i ++)
    {
        insert_node(inser_value[i],first_node,&querry_success_num,max_size);
    }
    double ASLsucc = querry_success_num / 8;
    double len_sum = 0;
    for(int i = 0 ; i < 11 ; i ++)
    {
        len_sum += max_size[i];
    }
    double ASLunsucc = len_sum / 11;
    printf("--------------------------------\n");
    for(int i = 0 ; i < 11 ; i ++)
    {
        if(max_size[i] == 0)
        {
            printf("len %d :NULL\n",i);
            continue;
        }
        node* current = first_node[i];
        printf("len %d :",i);
        while(current != NULL)
        {
            printf("%d ",current->value);
            current = current ->next;
        }
        printf("\n");
    }
    printf("--------------------------------\n");
    printf("ASLsucc is : %lf\n",ASLsucc);
    printf("ASLunsucc is : %lf",ASLunsucc); 
    return 0;
}

//注意指针移动
//注意值的初始化
//注意代码逻辑