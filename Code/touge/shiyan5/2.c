#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	/**********Begin**********/
    srand((unsigned int)time(NULL));
    int dice_result = rand() % 6 + 1;
	printf("Dice is: %d\n",dice_result);
    if(dice_result%2==0) printf("win");
	else printf("lose");
	/**********End**********/
	return 0;
} 