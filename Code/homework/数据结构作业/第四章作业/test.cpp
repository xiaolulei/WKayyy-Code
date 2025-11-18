#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype> // 引入头文件用于处理字符大小写

using namespace std;

// 增加Trie树节点的最大数量，使其更健壮
const int MAX_NODES = 10000; 
const int MAX_WORDS = 100;
const int MAX_WORD_LEN = 100;

// son: Trie树的节点数组
// p: 存储待查找的单词
// ending_word_idx: 标记某个节点是否是单词的结尾，并存储其在p数组中的索引
// word_count: 待查找单词的数量
// idx: Trie树当前节点的数量
int son[MAX_NODES][26];
char p[MAX_WORDS][MAX_WORD_LEN];
// BUG修复：数组大小应与Trie树节点数匹配
int ending_word_idx[MAX_NODES]; 
int word_count = 0; // 显式初始化
int idx = 1; // Trie树的根节点为0，新节点从1开始

struct WordStat 
{
    int count = 0; // 出现次数，建议初始化
    vector<int> lines; // 出现位置所在行的行号
};

// 建立Trie树
void insert(const char* a, int word_index)
{
    int current_node = 0;
    for(int i = 0; i < strlen(a); i++)
    {
        // 优化：处理非小写字母的情况
        if (!islower(a[i])) continue; // 如果不是小写字母，直接跳过
        int x = a[i] - 'a';
        if(!son[current_node][x]) {
            son[current_node][x] = idx++;
        }
        current_node = son[current_node][x];
    }
    ending_word_idx[current_node] = word_index;
}

// 在单行文本中搜索单词
void search_in_line(const string& line, int line_num, vector<WordStat>& stats) 
{
    for (int i = 0; i < line.length(); ++i) 
    {
        int current_node = 0;
        for (int j = i; j < line.length(); j++) {
            // 优化：忽略非小写字母
            if (!islower(line[j])) break; 
            
            int u = line[j] - 'a';
            if (!son[current_node][u]) break; // 如果路径不存在，中断内部循环
            
            current_node = son[current_node][u];

            // 检查当前节点是否代表一个完整的单词
            if (ending_word_idx[current_node] != -1) 
            {
                int found_idx = ending_word_idx[current_node];
                stats[found_idx].count++;
                
                // 防止同一行重复记录行号
                if (stats[found_idx].lines.empty() || stats[found_idx].lines.back() != line_num)
                {
                    stats[found_idx].lines.push_back(line_num);
                }
            }
        }
    }
}

int main() {
    // 初始化Trie树相关数组
    memset(son, 0, sizeof(son));
    memset(ending_word_idx, -1, sizeof(ending_word_idx));

    cout << "Please enter the words. End with 'END':" << endl;

    // 输入待统计的词汇
    while (word_count < MAX_WORDS) 
    {
        cin >> p[word_count];
        if (strcmp(p[word_count], "END") == 0) break;
        // 假设所有要查询的单词都是小写
        insert(p[word_count], word_count);
        word_count++;
    }

    cout << "\nPlease enter the code. End with 'EOF':" << endl;


    string line;
    int line_num = 1;
    vector<WordStat> stats(word_count); // 为每个词汇创建一个统计对象

    // 循环读取文本内容直到遇到"EOF"
    while (getline(cin, line) && line != "EOF") 
    {
        // 可以将文本行统一转为小写，以实现不区分大小写的匹配
        // transform(line.begin(), line.end(), line.begin(), ::tolower);
        search_in_line(line, line_num, stats);
        line_num++;
    }

    // 输出统计结果
    cout << "\n--------------------" << endl;
    for (int i = 0; i < word_count; ++i) {
        cout << "Word \"" << p[i] << "\":" << endl;
        cout << "  Count: " << stats[i].count << endl;
        if (!stats[i].lines.empty()) 
        {
            cout << "  Line: ";
            for (int j = 0; j < stats[i].lines.size(); j++) 
            {
                cout << stats[i].lines[j] << (j == stats[i].lines.size() - 1 ? "" : ", ");
            }
            cout << endl;
        } 
        else 
        {
            cout << "  None" << endl;
        }
        cout << "--------------------" << endl;
    }

    return 0;
}
