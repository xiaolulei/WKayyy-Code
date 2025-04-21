#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef tuple<int,int,int,int>  PIIII;

int merge(vector<PIIII> &segs)
{
    int ans=0,stx=-2e9,sty=-2e9,edx=-2e9,edy=-2e9;
    
    for(auto seg:segs)
    {
        //if(edx < seg.third && edy < seg.fourth)
    }

    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<PIIII> ans;
    for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ans.push_back({x1,y1,x2,y2});
    }
    int ans_num=merge(ans);
    cout << ans_num << endl;
    return 0;
}