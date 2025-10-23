#include <iostream>

using namespace std;

const int N = 5e4 + 10;

int n,k,res;
int p[N],d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        /*
        这里先存储根再进行dx的计算的原因如下：
        看起来main函数中确实有对d的操作，但实际上他们只是对根不同的d进行了修正
        举个例子来说
        当我们c == 1 也就是当x y的关系是平等的时候，我们x y的理论上的位置应该是相同，但是有时候他们的绝对位置在合并之后其实是不同的
        举个例子来说可能在原本的根里，我们的dx是2 但是dy是3 我们要合并到一个根里边的话这就和我们的算法不匹配
        我们是要看节点到根的距离的
        所以我们就需要修正，将x的根节点和y的根节点之间补充一点距离，实际上这对根其实没什么影响
        他的实际意义就是为了修正而存在的
        顺着上边的例子，我们把x的根节点与y的根节点直接差1，这时候x和y相对同一个根的距离就是相同的
        */
        p[x] = t;
    }
    return p[x];
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 1 ; i <= n ; i ++)
    {
        p[i] = i;
    }
    for(int i = 1 ; i <= k ; i ++)
    {
        int x,y,c;
        scanf("%d%d%d",&c,&x,&y);
        if(x > n || y > n) res ++;
        else
        {
            int px = find(x), py = find(y);
            if(c == 1)
            {
                if (px == py && (d[x] - d[y]) % 3) res ++ ;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];    
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    
    printf("%d\n", res);

    return 0;
}