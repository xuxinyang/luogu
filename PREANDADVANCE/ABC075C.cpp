#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m, cnt, idx, dfn[N], low;
vector<int> g[N];
int tarjan(int u, int fa)
{
    int lowu = dfn[u] = ++idx;
    for (int v : g[u])
    {
        if (!dfn[v])
        {
            int lowv = tarjan(v, u);
            lowu = min(lowu, lowv);
            if (lowv > dfn[u])
                cnt++;
        }
        else if (v != fa)
            lowu = min(lowu, dfn[v]);
    }
    return lowu;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            low = tarjan(i, 0);
    cout << cnt << endl;
    return 0;
}