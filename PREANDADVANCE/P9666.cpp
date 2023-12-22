#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int t, n, m, fa[maxn], ans[maxn<<1], p;
struct Edge
{
    int u, v;
};
Edge edges[maxm];
vector<pair<int, int> > es[maxm<<1];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v)
{
    int fx = find(u), fy = find(v);
    if (fx != fy) fa[fy] = fx;
}
bool dfs(int root, int now, int last)
{
    if (now == root) return 1;
    for (auto c : es[now])
    {
        if (c.first == last) continue;
        ans[++p] = c.second;
        if (dfs(root, c.first, now)) return 1;
        --p;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            es[i].clear();
        }
        p = 0;
        int u, v;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v;
            edges[i] = Edge{u, v};     
        }
        int k = 0;
        for (int i = 1; i <= m; i++)
        {
            int u = edges[i].u, v = edges[i].v;
            if (find(u) == find(v))
            {
                if (dfs(u, v, u))
                {
                    ans[++p] = i;
                    sort(ans + 1, ans + p + 1);
                    for (int i = 1; i <= p; i++) cout << ans[i] << " ";
                    cout << "\n";
                    break;
                }
                continue;
            }
            es[u].push_back(make_pair(v, i));
            es[v].push_back(make_pair(u, i));
            merge(u, v);
            if (i == m) 
            {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}