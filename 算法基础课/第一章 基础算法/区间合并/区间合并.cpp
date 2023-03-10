#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
typedef pair<int, int> PII;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for(auto seg : segs)
    {
        if(ed < seg.first)
        {
            if(st != -2e9)res.push_back({st, ed});
            st = seg.first;
            ed = seg.second;
        }
        else
        {
            ed = max(ed, seg.second);
        }
    }
    if(st != -2e9)res.push_back({st,ed});

    segs = res;
}
int main()
{
    scanf("%d", &n);
    while(n--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }
    merge(segs);

    cout << segs.size() <<endl;
}


