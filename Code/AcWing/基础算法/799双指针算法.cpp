#include <iostream>

using namespace std;

const int N = 1e5+10;
int n,res;
int s[N],q[N];

int main()
{
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d",&q[i]);
  }
  for(int i = 0, j = 0; i < n; i++)
  {
    s[q[i]]++;
    while(s[q[i]] > 1)
    {
      s[q[j]]--;
      j++;
    }
    res = max (res, i - j + 1);
  }
  
  cout << res << endl;
  return 0;
}