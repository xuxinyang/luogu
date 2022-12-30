#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n, m, s;
int tot;
int head[maxn], d[maxn], f[maxn][25];
struct Edge
{
    int to;
    int next;
};
Edge edges[maxn<<1];
void add(int u, int v)
{
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot; 
}
void dfs(int u, int v)
{
    d[u] = d[v] + 1;
    f[u][0] = v;
    for (int i = 1; (1 << i) <= d[u]; i++)
    {
        f[u][i] = f[f[u][i-1]][i-1];
    }
    for (int i = head[u]; ~i; i = edges[i].next)
    {
        int tmp = edges[i].to;
        if (tmp != v) dfs(tmp, u);
    }
}
int lca(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
    int k = log2(n);
    for (int i = k; i >= 0; i--)
    {
        if (d[u] <= d[v] - (1<<i))
            v = f[v][i];
    }
    if (u == v) return u;
    for (int i = k; i >= 0; i--)
    {
        if (f[u][i] == f[v][i]) continue;
        else u = f[u][i], v = f[v][i];
    }
    return f[u][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs(s, 0);
    while (m--)
    {
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}


