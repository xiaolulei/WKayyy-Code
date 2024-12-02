#include<stdio.h>
// v7,0,10    V7是数组
int __cdecl sub_4010F0(char* a1, int a2, int a3)
{
  int result; // eax
  int i; // esi
  int v5; // ecx
  int v6; // edx

  result = a3;
  for ( i = a2; i <= a3; a2 = i )
  {
    v5 = 4 * i;
    v6 = a1[i];
    if ( a2 < result && i < result )
    {
      do
      {
        if ( v6 > a1[result] )
        {
          if ( i >= result )
            break;
          ++i;
          a1[v5/4] = a1[result];
          if ( i >= result )
            break;
          while ( a1[i] <= v6 )
          {
            if ( ++i >= result )
              goto LABEL_13;
          }
          if ( i >= result )
            break;
          v5 = 4 * i;
         a1[result] = a1[i];
        }
        --result;
      }
      while ( i < result );
    }
LABEL_13:
    a1[result] = v6;
    sub_4010F0(a1, a2, i - 1);
    result = a3;
    ++i;
  }
  return result;
}
int main()
{
    char str[] = "ZJSECaNH3ng";
    sub_4010F0(str,0,10);
	printf("%s", str);
	return 0;
}