#include <bits/stdc++.h>
using namespace std;
int a[12][4];
inline int h(int sta)
{
    int s1 = (0x444444 - (sta & 0x333333)) & 0x333333;
    int s2 = (0x1111110 - (sta & 0xcccccc)) & 0xcccccc;
    int tmp = __builtin_popcount((s1 | s2) & 0x555555);
    int pace = __builtin_popcount(s1 | s2) * 2 - tmp;
    return pace + 1 >> 1;
}
inline int move(int sta, int id)
{
    int single_sta = ((sta >> id + id) & 3);
    int chain = a[id][single_sta];
    int chain_sta = ((sta >> chain + chain) & 3);

    single_sta = (single_sta + 1) & 3;
    chain_sta = (chain_sta + 1) & 3;
    int msk = ((3 << id + id) | (3 << chain + chain));
    return sta & (~msk) | (single_sta << id + id) | (chain_sta << chain + chain);
}

struct node
{
    int sta;
    int gv, hv, fv;
    inline node(int sta_ = 0, int gv_ = 0) : sta(sta_), gv(gv_)
    {
        hv = h(sta_);
        fv = gv + hv;
    }
    inline friend bool operator<(const node &a, const node &b)
    {
        return a.fv > b.fv;
    }
};
priority_queue<node> pq;
int fr[1 << 24], pace[1 << 24];
bool vis[1 << 24];
inline void EPEA_star(int sta)
{
    while (!pq.empty())
        pq.pop();
    pq.emplace(sta, 0);
    fr[sta] = -1;
    pace[sta] = -1;
    vis[sta] = 1;

    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        if (now.sta == 0) // target state
            break;

        int nxtf = -1;
        for (int i = 0; i < 12; ++i)
        {
            int nxtsta = move(now.sta, i);
            if (vis[nxtsta])
                continue;
            int f = now.gv + 1 + h(nxtsta);
            if (f < now.fv) // expanded
                continue;
            else if (f == now.fv)
            { // expand
                pq.emplace(nxtsta, now.gv + 1);
                fr[nxtsta] = now.sta;
                pace[nxtsta] = i;
                vis[nxtsta] = 1;
            }
            else if (nxtf == -1)
                nxtf = f;
            else
                nxtf = min(nxtf, f);
        }
        if (nxtf == -1)
            continue;
        now.fv = nxtf;
        pq.push(now);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ini_sta = 0;
    for (int i = 0; i < 12; ++i)
    {
        int s;
        cin >> s;
        ini_sta |= (s - 1 << i + i);
        for (int j = 0; j < 4; ++j)
        {
            cin >> a[i][j];
            --a[i][j];
        }
    }
    EPEA_star(ini_sta);

    vector<int> v;
    for (int sta = 0; ~fr[sta]; sta = fr[sta])
        v.push_back(pace[sta]);
    reverse(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto e : v)
        cout << e + 1 << " ";
    return 0;
}