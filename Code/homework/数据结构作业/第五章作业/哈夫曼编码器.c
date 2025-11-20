#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxcapacity 1000

typedef struct HuffmanNode
{
    char ch;
    int frequent;
    struct HuffmanNode *left,*right;
}huffmannode;

typedef struct MinHeap
{
    int size;
    int capacity;
    huffmannode** arr;
}minheap;

typedef struct {
    unsigned long long bits; 
    int len;                
} CodeBuffer;
//用位段存储编码

huffmannode* createhuffmannode(char ch,int frequent)
{
    huffmannode* temp = (huffmannode*)malloc(sizeof(huffmannode));
    temp->ch = ch;
    temp->frequent = frequent;
    temp->left = temp->right = NULL;
    return temp;
}

minheap* createminheap(int size)
{
    minheap* temp = (minheap*)malloc(sizeof(minheap));
    temp->size = size;
    temp->capacity = maxcapacity;
    temp->arr = (huffmannode**)malloc(sizeof(huffmannode*) * maxcapacity);
    return temp;
}

void swaphuffmannode(huffmannode** a,huffmannode** b)
{
    huffmannode* t = *a;
    *a = *b;
    *b = t;
}

void minheapify(minheap* heap,int idx)
{
    int small = idx;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    if(left < heap->size && heap->arr[small]->frequent > heap->arr[left]->frequent)
    {
        small = left;
    }
    if(right < heap->size && heap->arr[small]->frequent > heap->arr[right]->frequent)
    {
        small = right;
    }
    if(small != idx)
    {
        swaphuffmannode(&heap->arr[small],&heap->arr[idx]);
        minheapify(heap,small);
    }
}

minheap* buildminheap(char str[],int frequent[],int size)
{
    minheap* heap = createminheap(size);
    heap->size = size;
    for(int i = 0; i < size; i++)
    {
        heap->arr[i] = createhuffmannode(str[i],frequent[i]);
    }
    for(int i = (heap->size - 2) / 2; i >= 0; --i)
    {
        minheapify(heap,i);
    }
    return heap;
}

void inserthuffmannode(huffmannode* a,minheap* heap)
{
    if(heap->size + 1 > heap->capacity)
    {
        printf("error\n");
        return;
    }
    ++heap->size;
    int i = heap->size - 1;
    while(i && a->frequent < heap->arr[(i - 1) / 2]->frequent)
    {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arr[i] = a;
}

huffmannode* gettop(minheap* heap)
{
    huffmannode* temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    --heap->size;
    minheapify(heap,0);
    return temp;
}

huffmannode* createhuffmantree(minheap* heap)
{
    while(heap->size != 1)
    {
        huffmannode* left = gettop(heap);
        huffmannode* right = gettop(heap);

        huffmannode* top = createhuffmannode('#',left->frequent + right->frequent);
        top->left = left;
        top->right = right;
        inserthuffmannode(top,heap);
    }
    return heap->arr[0];
}

void savehuffmannode(huffmannode* top,FILE* hfmantree)
{
    if(!top) return;
    if(!top->left && !top->right)
    {
        fprintf(hfmantree,"%d %c\n",top->frequent,top->ch);
    }
    savehuffmannode(top->left,hfmantree);
    savehuffmannode(top->right,hfmantree);
}

huffmannode* readhuffmantree(FILE* hfmantree,int frequent[],char str[])
{
    int freq;
    char ch;
    int arr_idx = 0;
    while(fscanf(hfmantree,"%d %c",&freq,&ch) != EOF)
    {
        frequent[arr_idx] = freq;
        str[arr_idx] = ch;
        arr_idx++;
    }
    if(arr_idx == 0) return NULL;
    return createhuffmantree(buildminheap(str,frequent,arr_idx));
}

int gethuffmancode(huffmannode* node, CodeBuffer current, FILE* codefile, char target)
{
    if(!node) return 0;

    if(!node->left && !node->right)
    {
        if(node->ch == target)
        {
            for(int i = current.len - 1; i >= 0; --i)
            {
                int bit = (current.bits >> i) & 1;
                fprintf(codefile, "%d", bit);
            }
            return 1;
        }
        return 0;
    }

    CodeBuffer leftCode = current;
    leftCode.bits = (current.bits << 1); 
    leftCode.len++;
    if(gethuffmancode(node->left, leftCode, codefile, target)) return 1;

    CodeBuffer rightCode = current;
    rightCode.bits = (current.bits << 1) | 1;
    rightCode.len++;
    if(gethuffmancode(node->right, rightCode, codefile, target)) return 1;

    return 0;
}

void decodecodefile(FILE* codefile,FILE* textfile,huffmannode* top)
{
    if(!codefile || !textfile || !top) return;
    huffmannode* node = top;
    int ch;
    while((ch = fgetc(codefile)) != EOF)
    {
        if(ch != '0' && ch != '1') continue;

        if(ch == '0') node = node->left;
        else node = node->right;

        if(node && !node->left && !node->right)
        {
            fputc(node->ch,textfile);
            node = top;
        }
    }
}

void printfdecode(FILE* codefile,FILE* codeprin)
{
    int ch;
    int idx = 0;
    while((ch = fgetc(codefile)) != EOF)
    {
        if(ch != '0' && ch != '1') continue;
        
        printf("%c",ch);
        fprintf(codeprin,"%c",ch);
        ++idx;
        if(idx == 50)
        {
            printf("\n");
            fprintf(codeprin,"\n");
            idx = 0;
        }
    }
    printf("\n");
    fprintf(codeprin,"\n");
}

void print_tree_structure(huffmannode* node, char* prefix, int is_left, FILE* file)
{
    if(node == NULL) return;

    printf("%s", prefix);
    fprintf(file, "%s", prefix);

    if(is_left != -1) 
    {
        const char* connector = is_left ? "|-- " : "\\-- ";
        printf("%s", connector);
        fprintf(file, "%s", connector);
    }

    if(!node->left && !node->right)
    {
        printf("[%c : %d]\n", node->ch, node->frequent);
        fprintf(file, "[%c : %d]\n", node->ch, node->frequent);
    }
    else
    {
        printf("[# : %d]\n", node->frequent);
        fprintf(file, "[# : %d]\n", node->frequent);
    }
    char new_prefix[2000];
    strcpy(new_prefix, prefix);
    if(is_left == 1)
    {
        strcat(new_prefix, "|   ");
    }
    else if(is_left == 0)
    {
        strcat(new_prefix, "    ");
    }

    print_tree_structure(node->left, new_prefix, 1, file);
    print_tree_structure(node->right, new_prefix, 0, file);
}

void printtree(huffmannode* node, int depth, FILE* file)
{
    char prefix[2000] = ""; 
    printf("Huffman Tree Structure:\n");
    print_tree_structure(node, prefix, -1, file);
}

int main()
{
    FILE *hfmantree,*tobetran,*codefile,*textfile,*codeprin,*treeprin;
    char choice = ' ';
    huffmannode* top = NULL;
    int frequent[maxcapacity];
    char str[maxcapacity];
    printf("Choice:");
    printf("\n I : Initiate");
    printf("\n E : Encode");
    printf("\n D : Decode");
    printf("\n P : PrintCode");
    printf("\n T : PrintTree");
    printf("\n Q : Quit\n");
    while(choice != 'Q')
    {
        scanf(" %c",&choice);
        switch(choice)
        {
        case 'I':
            hfmantree = fopen("HFMANTREE.txt","w");
            int N;
            scanf("%d",&N);
            for(int i = 0; i < N; i++) scanf(" %c",&str[i]);
            for(int i = 0; i < N; i++) scanf("%d",&frequent[i]);
            
            minheap* myheap = buildminheap(str,frequent,N);
            top = createhuffmantree(myheap);
            savehuffmannode(top,hfmantree);
            fclose(hfmantree);
            break;

        case 'E':
            if(top == NULL)
            {
                hfmantree = fopen("HFMANTREE.txt","r");
                if(hfmantree)
                {
                    top = readhuffmantree(hfmantree,frequent,str);
                    fclose(hfmantree);
                }
                if(top == NULL)
                {
                    printf("Error! No Data!\n");
                    break;
                }
            }
            tobetran = fopen("TOBETRAN.txt","r");
            if(tobetran == NULL)
            {
                printf("Error! No TOBETRAN.txt!\n");
                break;
            }
            codefile = fopen("CODEFILE.txt","w");
            if(codefile == NULL)
            {
                printf("Error! Cannot create CODEFILE.txt!\n");
                fclose(tobetran);
                break;
            }
            
            int textCh;
            while((textCh = fgetc(tobetran)) != EOF)
            {
                if(textCh == '\n' || textCh == '\r') continue;
                CodeBuffer startCode = {0, 0};
                gethuffmancode(top, startCode, codefile, (char)textCh);
            }
            fclose(codefile);
            fclose(tobetran);
            break;

        case 'D':
            if(top == NULL)
            {
                printf("Error! No Huffman Tree!\n");
                break;
            }
            codefile = fopen("CODEFILE.txt","r");
            if(codefile == NULL)
            {
                printf("Error! No CODEFILE.txt!\n");
                break;
            }
            textfile = fopen("TEXTFILE.txt","w");
            if(textfile == NULL)
            {
                printf("Error! Cannot create TEXTFILE.txt!\n");
                fclose(codefile);
                break;
            }
            decodecodefile(codefile,textfile,top);
            fclose(codefile);
            fclose(textfile);
            break;

        case 'P':
            codefile = fopen("CODEFILE.txt","r");
            if(codefile == NULL)
            {
                printf("Error! No CODEFILE.txt!\n");
                break;
            }
            codeprin = fopen("CODEPRIN.txt","w");
            if(codeprin == NULL)
            {
                printf("Error! Cannot create CODEPRIN.txt!\n");
                fclose(codefile);
                break;
            }
            printfdecode(codefile,codeprin);
            fclose(codefile);
            fclose(codeprin);
            break;

        case 'T':
            if(top == NULL)
            {
                hfmantree = fopen("HFMANTREE.txt","r");
                if(hfmantree)
                {
                    top = readhuffmantree(hfmantree,frequent,str);
                    fclose(hfmantree);
                }
                if(top == NULL)
                {
                    printf("Error! No Tree in Memory!\n");
                    break;
                }
            }
            treeprin = fopen("TREEPRIN.txt","w");
            if(treeprin == NULL)
            {
                printf("Error! Cannot create TREEPRIN.txt!\n");
                break;
            }
            printtree(top, 0, treeprin);
            fclose(treeprin);
            printf("\nTree saved to TREEPRIN.txt\n");
            break;

        default:
            break;
        }
    }
    return 0;
}