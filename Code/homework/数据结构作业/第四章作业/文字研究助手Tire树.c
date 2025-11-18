#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 100
#define MAX_LEN_LENGTH 10000

int son[MAX_LEN_LENGTH][26];
char p[MAX_WORDS][MAX_WORD_LEN];
int ending_word_idx[MAX_LEN_LENGTH];
int word_count;
int idx;

typedef struct
{
    int idx;
    int count; //出现次数
    int lines[100]; //出现位置所在行的行号 我们同样是假设一个关键字在代码中出现的次数最多为100次
} WordStat;

//建立树
void insert(const char* a,int b)
{
    int p = 0;
    int len = strlen(a);
    for(int i = 0 ; i < len; i ++)
    {
        int x;
        if((a[i] > 'A' || a[i] == 'A') && (a[i] < 'Z' || a[i] == 'Z'))
            x = a[i] - 'A';
        else
            x = a[i] - 'a';
        if(!son[p][x]) son[p][x] = idx ++;
        p = son[p][x];
    }
    ending_word_idx[p] = b;
}

void search_in_line(char* line, int line_num, WordStat* stats) 
{
    for (int i = 0; i < strlen(line); ++i) 
    {
        int p = 0;
        for (int j = i; j < strlen(line); j ++) 
        {
            int u;
            if(!((line[j] >= 'a' && line[j] <= 'z') || (line[j] >= 'A' && line[j] <= 'Z'))) break;
            if(line[j] >= 'A' && line[j] <= 'Z')
                u = line[j] - 'A';
            else
                u = line[j] - 'a';
            if(!son[p][u]) break;
            p = son[p][u];

            if (ending_word_idx[p] != -1) 
            {
                int found_idx = ending_word_idx[p];
                stats[found_idx].count++;
                int already_recorded = 0; //替代bool检查是否已经有这个行号了
                for(int k = 0; k < stats[found_idx].idx; k++) 
                {
                    if(stats[found_idx].lines[k] == line_num) 
                    {
                        already_recorded = 1;
                        break;
                    }
                }
                if (!already_recorded) 
                {
                    stats[found_idx].lines[stats[found_idx].idx] = line_num;
                    stats[found_idx].idx++;
                }
            }
        }
    }
}


int main() {
    printf("Please enter the words. End with 'END':\n");
    memset(ending_word_idx,-1,sizeof(ending_word_idx));
    //输入待统计的词汇
    while (word_count < MAX_WORDS) 
    {
        scanf("%s",p[word_count]);
        if(strcmp(p[word_count], "END") == 0) break;
        insert(p[word_count],word_count);
        word_count++;
    }

    while(getchar() != '\n'); 

    printf("\nPlease enter the code. End with 'EOF':\n");
    char line[1000];
    int line_num = 1;
    WordStat stats[word_count]; //为每个词汇创建一个统计对象
    memset(stats,0,sizeof(stats));

    while(fgets(line, sizeof(line), stdin) != NULL) 
    {
        search_in_line(line,line_num,stats);
        line_num++;
    }

    printf("\n--------------------\n");
    for (int i = 0; i < word_count; ++i) {
        printf("\"Word\": %s\n",p[i]);
        printf("\"Cout\": %d\n",stats[i].count);
        if (stats[i].count > 0) 
        {
            printf("line: ");
            for (int j = 0; j < stats[i].idx; j ++) 
            {
                printf("%d ",stats[i].lines[j]);
            }
            printf("\n");
        } 
        else 
        {
            printf("  None \n");
        }
        printf("--------------------\n");
    }

    return 0;
}