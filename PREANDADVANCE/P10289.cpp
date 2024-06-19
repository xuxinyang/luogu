#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int inf = 0x3f3f3f3f;
int n, k, m, d[maxn], dis[maxn], f[maxn][19];
vector<int> edge[maxn];
queue<int> q;
void dfs(int u, int fa)
{
    d[u] = d[fa]+1, f[u][0] = fa;
    for (int i = 1; i <= 18; i++) f[u][i] = f[f[u][i-1]][i-1];
    for (int v:edge[u]) if (v!=fa) dfs(v, u);
}
int lca(int x, int y)
{
    if (d[x] < d[y]) swap(x, y);
    for (int i = 18; i >= 0; i--) 
        if (d[f[x][i]] >= d[y]) x = f[x][i];
    if (x == y) return x;
    for (int i = 18; i >= 0; i--) 
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> k >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= k; i++)
    {
        int u;
        cin >> u;
        q.push(u), dis[u] = 0;
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v:edge[u])
            if (dis[v] == inf) dis[v] = dis[u]+1, q.push(v);
    }
    dfs(1, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << (min(d[u]+d[v]-2*d[lca(u, v)], dis[u]+dis[v])) << "\n";
    }
    return 0;
}