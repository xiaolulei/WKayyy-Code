#include <stdio.h>
#include <string.h>

int main()
{
    FILE* output;
    output = fopen("output.txt","w");
    printf("Please enter the word you want to input. End with \"EOF\"\n" );
    printf("------------\n");
    char line[100]; //假设一行不超过100字符 可多行输入
    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        if(strcmp(line,"EOF") == 0) break;
        int pindu[37];
        memset(pindu,0,sizeof(pindu));
        for(int i = 0 ; i < strlen(line) ; i ++)
        {
            if(line[i] < 'A' || line[i] > 'Z')
            {
                if(line[i] >= '0' && line[i] <= '9')
                {
                    pindu[line[i] - '0' + 26] ++;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                pindu[line[i] - 'A' ] ++;
            }
        }
        for(int i = 0 ; i < 36 ; i ++) fprintf(output,"%d ",pindu[i]);
        fprintf(output,"\n");
    }
    fclose(output);
    return 0;
}