#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100 // 假设最多统计100个词汇
#define MAX_WORD_LEN 10 // 假设每个词汇最大长度为10

int ne[MAX_WORDS][MAX_WORD_LEN];
char p[MAX_WORDS][MAX_WORD_LEN];
int word_count = 0;

typedef struct
{
    int idx;
    int count; //出现次数
    int lines[100]; //出现位置所在行的行号 我们同样是假设一个关键字在代码中出现的次数最多为100次
} WordStat;

void calculate_next(const char* p, int p_idx) 
{
    int m = strlen(p);
    ne[p_idx][0] = 0;
    for (int i = 1, j = 0; i < m; i++) 
    {
        while(j && p[i] != p[j]) j = ne[p_idx][j - 1];
        if (p[i] == p[j]) j++;
        ne[p_idx][i] = j;
    }
}

void KMP(const char* text, const char* p, int p_idx, int line_num, WordStat* stat) 
{
    int n = strlen(text);
    int m = strlen(p);
    int found_in_line = 0;

    for (int i = 0, j = 0; i < n; i++) 
    {
        while (j > 0 && text[i] != p[j]) j = ne[p_idx][j - 1];
        if (text[i] == p[j]) j++;
        if (j == m) 
        {
            stat->count++;
            found_in_line = 1;
            j = ne[p_idx][j - 1];
        }
    }

    if (found_in_line) 
    {
        //查找是否有重复
        for(int i = 0 ; i < stat->idx ; i ++)
        {
            if(stat->lines[i] == line_num) return;
        }
        stat->lines[stat->idx] = line_num;
        stat->idx++;
    }
}

int main() {
    printf("Please enter the words. End with 'END':\n");
    //输入待统计的词汇
    while(word_count < MAX_WORDS) 
    {
        scanf("%s",p[word_count]);
        if(strcmp(p[word_count], "END") == 0) break;
        calculate_next(p[word_count], word_count);
        word_count++;
    }

    while(getchar() != '\n');

    printf("\nPlease enter the code. End with 'EOF':\n");

    char line[1000];
    int line_num = 1;
    WordStat stats[word_count]; //为每个词汇创建一个统计对象
    for(int i = 0; i < word_count; i++) 
    {
        memset(&stats[i],0,sizeof(WordStat));
    }

    while(fgets(line, sizeof(line), stdin) != NULL) 
    {
        if (strcmp(line, "EOF") == 0) break;
        for(int i = 0; i < word_count; ++i) 
        {
            KMP(line, p[i], i, line_num, &stats[i]);
        }
        line_num++;
    }

    //输出统计结果
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