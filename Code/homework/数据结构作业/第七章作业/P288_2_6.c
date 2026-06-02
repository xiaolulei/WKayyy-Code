#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int insert_node(int num, int* hash, int* find_it)
{
    int start_idx = num % 7;
    int idx = start_idx;
    if(hash[idx] == -1)
    {
        hash[idx] = num;
        (*find_it)++;
    } 
    else
    {
        int count = 1; 
        int position[10] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5};
        int i = 0;
        while(i < 10)
        {
            int temp = start_idx + position[i];
            i++; 
            if(temp < 0 || temp > 9) continue;
            idx = temp;
            count++;
            if(hash[idx] == -1)
            {
                hash[idx] = num;
                *find_it = *find_it + count;
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

void init_hash(int* hash)
{
    for(int i = 0 ; i < 10 ; i ++)
    {
        hash[i] = -1;
    }
}

int main()
{
    int hash[10];
    init_hash(hash);
    int insert_num[8] = {9, 1, 23, 14, 55, 20, 84, 27};
    int find_it = 0;
    for(int i = 0 ; i < 8 ; i ++)
    {
        int if_success = insert_node(insert_num[i], hash, &find_it);
        if(!if_success)
        {
            printf("%d Error!!!\n", insert_num[i]);
            return 0;
        }
    }
    
    printf("Hash Table: ");
    for(int i=0; i<10; i++) printf("%d ", hash[i]);
    printf("\n");
    
    printf("Total Comparisons: %d\n", find_it);
    printf("ASL : %f", (double)find_it / 8);
    
    return 0;
}