#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e6+5;
vector<int> g[N];
vector<pair<int, int>> q[N];
int fa[N], vis[N], ans[N];
int n, m, p;
inline void addEdge(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
inline void addQuery(int u, int v, int ID)
{
    q[u].push_back({v, ID});
    q[v].push_back({u, ID});
}
inline int find(int x)
{
    return x==fa[x]?x:fa[x] = find(fa[x]);
}
void dfs(int u)
{
    fa[u] = u;
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (vis[v]) continue;
        dfs(v);
        fa[v] = u;
    }
    for (auto e : q[u])
    {
        int v = e.first;
        if (!vis[v]) continue;
        ans[e.second] = find(v);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        addQuery(x, y, i);
    }
    dfs(p);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
    return 0;
}