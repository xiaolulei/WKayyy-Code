#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> PII;

void merge(vector<PII> &segs)
{
    vector<PII> temp;
    sort(segs.begin(),segs.end());

    int st=-2e9,ed=-2e9;
    for(auto seg:segs)
    {
        if(ed < seg.first)
        {
            if(ed != -2e9) temp.push_back({st,ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed,seg.second);
    }
    if(st != -2e9) temp.push_back({st,ed});
    segs = temp;
}


int main()
{
    int n;
    cin >> n;
    vector<PII> segs;
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        segs.push_back({l,r});
    }
    merge(segs);
    cout << segs.size() << endl ;
    return 0;  
}
