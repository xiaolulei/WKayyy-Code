#include <iostream>

using namespace std;

#define MAX_SIZE 100010
int num[MAX_SIZE] = {1};
int ne[MAX_SIZE];

int current;

int main()
{
  int count;
  scanf("%d",&count);
  for(int i = 1 ; i <= count ; i ++)
  {
    int sort;
    scanf("%d",&sort);
    if(sort == 1)
    {
      int x,y;
      scanf("%d %d",&x,&y);
      for(int j = 0 ; j <= current ; j ++)
      {
        if(num[j] == x)
        {
          if(ne[j] == 0)
          {
            ne[j] = ++current;
          }
          else
          {
            int temp = ne[j];
            ne[j] = ++current;
            ne[current] = temp; 
          }
          num[current] = y;
          break;
        }
      }
    }
    else if(sort == 2)
    {
      int x;
      scanf("%d",&x);
      for(int j = 0 ; j <= current; j ++)
      {
        if(num[j] == x)
        {
          if(ne[j] == 0)
          {
            printf("0\n");
          }
          else
          {
            printf("%d\n",num[ne[j]]);
          }
          break;
        }
      }
    }
    else if(sort == 3)
    {
      int x;
      scanf("%d",&x);
      for(int j = 0 ; j <= current ; j ++)
      {
        if(num[j] == x)
        {
          if(ne[j] != 0)
            {
              num[ne[j]] = 0;
              ne[j] = ne[ne[j]];
            }
          break;
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return 0;
}