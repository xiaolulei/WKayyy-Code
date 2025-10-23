#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_WORDS = 100; // 假设最多统计100个词汇
const int MAX_WORD_LEN = 100; // 假设每个词汇最大长度为100

int ne[MAX_WORDS][MAX_WORD_LEN];
char patterns[MAX_WORDS][MAX_WORD_LEN];
int word_count = 0;

struct WordStat 
{
    int count; // 出现次数
    vector<int> lines; // 出现位置所在行的行号
};

void calculate_next(const char* p, int p_idx) 
{
    int m = strlen(p);
    ne[p_idx][0] = 0;
    for (int i = 1, j = 0; i < m; i++) 
    {
        while (j && p[i] != p[j]) j = ne[p_idx][j - 1];
        if (p[i] == p[j]) j++;
        ne[p_idx][i] = j;
    }
}

void kmp_search(const string& text, const char* p, int p_idx, int line_num, WordStat& stat) 
{
    int n = text.length();
    int m = strlen(p);
    bool found_in_line = false;

    for (int i = 0, j = 0; i < n; i++) 
    {
        while (j > 0 && text[i] != p[j]) 
        {
            j = ne[p_idx][j - 1];
        }
        if (text[i] == p[j]) 
        {
            j++;
        }
        if (j == m) 
        {
            stat.count++;
            found_in_line = true;
            j = ne[p_idx][j - 1];
        }
    }

    if (found_in_line) 
    {
        if (find(stat.lines.begin(), stat.lines.end(), line_num) == stat.lines.end()) 
        {
            stat.lines.push_back(line_num);
        }
    }
}

int main() {
    cout << "Please enter the words. End with 'END':" << endl;

    // 1. 输入待统计的词汇
    while (word_count < MAX_WORDS) 
    {
        cin >> patterns[word_count];
        if (strcmp(patterns[word_count], "END") == 0) 
        {
            break;
        }
        calculate_next(patterns[word_count], word_count);
        word_count++;
    }

    cout << "\nPlease enter the code. End with 'EOF':" << endl;

    // 2. 逐行读入小说文本并进行统计
    string line;
    int line_num = 1;
    vector<WordStat> stats(word_count); // 为每个词汇创建一个统计对象

    while (getline(cin, line) && line != "EOF") 
    {
        for (int i = 0; i < word_count; ++i) 
        {
            kmp_search(line, patterns[i], i, line_num, stats[i]);
        }
        line_num++;
    }

    // 3. 输出统计结果
    cout << "\n--------------------" << endl;
    for (int i = 0; i < word_count; ++i) {
        cout << "Word \"" << patterns[i] << "\":" << endl;
        cout << "  Cout: " << stats[i].count << endl;
        if (stats[i].count > 0) 
        {
            cout << "  line: ";
            for (size_t j = 0; j < stats[i].lines.size(); j ++) 
            {
                cout << stats[i].lines[j] << (j == stats[i].lines.size() - 1 ? "" : ", ");
            }
            cout << endl;
        } 
        else 
        {
            cout << "  None " << endl;
        }
        cout << "--------------------" << endl;
    }

    return 0;
}