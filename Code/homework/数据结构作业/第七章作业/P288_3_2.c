#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

//判断一个二叉排序树的关键在于看它的数据是否在下界和上界之间
int judge_helper(node* root, node* min_node, node* max_node)
{
    // 空树是合法的二叉排序树
    if (root == NULL)
        return 1;

    // 如果设定了下界，且当前节点 <= 下界，则不合法
    if (min_node && root->data <= min_node->data)
        return 0;

    // 如果设定了上界，且当前节点 >= 上界，则不合法
    if (max_node && root->data >= max_node->data)
        return 0;

    // 递归判断：
    // 1. 左子树的所有节点必须小于当前节点（max_node 更新为 root）
    // 2. 右子树的所有节点必须大于当前节点（min_node 更新为 root）
    return judge_helper(root->left, min_node, root) && 
           judge_helper(root->right, root, max_node);
}

int bstree_judge(node* root)
{
    return judge_helper(root, NULL, NULL);
}

node* create_node(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode)
    {
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int main()
{
    node* root;

    printf("Test 1:Valid BST\n");
    root = create_node(4);
    root->left = create_node(2);
    root->right = create_node(6);
    root->left->left = create_node(1);
    root->left->right = create_node(3);
    if (bstree_judge(root))
        printf("It is a Binary Search Tree.\n");
    else
        printf("It is NOT a Binary Search Tree.\n");

    printf("Test 2: Invalid BST\n");
    root->left->right->data = 5; 

    if (bstree_judge(root))
        printf("It is a Binary Search Tree.\n");
    else
        printf("It is NOT a Binary Search Tree.\n");

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}