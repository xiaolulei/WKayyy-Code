#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str2[] = "ylqq]aycqyp{";
    for ( int i = 0; i < strlen(str2); ++i )
    {
    if ( ((str2[i] + 2 <= '`' || str2[i] + 2 > 98) && (str2[i] + 2 <= 64 || str2[i] + 2 > 66)) || ((str2[i] - 24 <= '`' || str2[i] - 24 > 98) && (str2[i] - 24 <= 64 || str2[i] - 24 > 66)) ) 
      str2[i] += 2;
    else
      str2[i] -= 24;
    }
    cout << str2;
    return 0;
}