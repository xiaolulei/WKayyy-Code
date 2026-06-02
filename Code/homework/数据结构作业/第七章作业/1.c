#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char value[15];
    struct node* next;
}node;

//因为英文字母有26个，所以我们设置26个根节点

node* new_node(char value[])
{
    node* temp = malloc(sizeof(node));
    strncpy(temp->value, value, sizeof(temp->value) - 1);
    temp -> next = NULL;
    return temp;
}

void insert_node(char value[],node** first_node)
{
    int idx = value[0] - 'a';
    if(first_node[idx] == NULL)
    {
        first_node[idx] = new_node(value);
    }
    else
    {
        node* current = first_node[idx];
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node(value);
    }
}

int search_node(node** first_node,char value[])
{
    if (value == NULL || value[0] == '\0') return 0;
    int idx = value[0] - 'a';
    if (first_node[idx] == NULL) return 0;
    node* current = first_node[idx];
    while (current != NULL) 
    {
        if (strcmp(current->value, value) == 0) return 1;
        current = current->next;
    }
    return 0;
}

//测试哈希表是否建立成功
void test_node(node** first_node)
{
    for(int i = 0 ; i < 26 ; i ++)
    {
        if(first_node[i] == NULL) continue;
        else
        {
            node* current = first_node[i];
            printf("%s",current->value);
            while(current->next != NULL)
            {
                current = current -> next;
                printf("->%s",current->value);
            }
            printf("\n");
        }
    }
}

int main()
{
    node** first_node = malloc(sizeof(node*) * 26);

    for(int i = 0 ; i < 26 ; i ++)
    {
        first_node[i] = NULL;
    }
    
    char value[34][15] = 
    {
        "beijing",        // 北京市
        "tianjin",        // 天津市
        "shanghai",       // 上海市
        "chongqing",      // 重庆市
        "hebei",          // 河北省
        "shanxi",         // 山西省
        "liaoning",       // 辽宁省
        "jilin",          // 吉林省
        "heilongjiang",   // 黑龙江省
        "jiangsu",        // 江苏省
        "zhejiang",       // 浙江省
        "anhui",          // 安徽省
        "fujian",         // 福建省
        "jiangxi",        // 江西省
        "shandong",       // 山东省
        "henan",          // 河南省
        "hubei",          // 湖北省
        "hunan",          // 湖南省
        "guangdong",      // 广东省
        "hainan",         // 海南省
        "sichuan",        // 四川省
        "guizhou",        // 贵州省
        "yunnan",         // 云南省
        "shannxi",         // 陕西省
        "gansu",          // 甘肃省
        "qinghai",        // 青海省
        "taiwan",         // 台湾省
        "neimenggu",      // 内蒙古自治区
        "guangxi",        // 广西壮族自治区
        "xizang",         // 西藏自治区
        "ningxia",        // 宁夏回族自治区
        "xinjiang",        // 新疆维吾尔自治区
        "xianggang",      // 香港特别行政区
        "aomen"           // 澳门特别行政区
    };

    for(int i = 0 ; i < 34 ; i ++)
    {
        insert_node(value[i],first_node);
    }
    printf("------------------------------------------\n");
    printf("Please Enter the node you want to search\n");
    char search[15];
    while(scanf("%s",search))
    {
        if(strcmp(search,"EOF") == 0) break;
        int if_find = search_node(first_node,search);
        if(if_find) printf("We find the %s\n",search);
        else printf("We not find %s\n",search);
    }
    return 0;
}