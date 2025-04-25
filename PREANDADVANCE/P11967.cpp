#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n, a, head[maxn], tot, badx, bady, f[maxn][21], dep[maxn], ans;
struct Edge
{
    int to, next;
} edges[maxn<<1];
int good[maxn], bad[maxn]; 
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i-1]][i-1];
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == fa) continue;
        dfs(v, u);
    }
}
int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    int k = log2(dep[u]);
    for (int i = k; i >= 0; i--)
        if (dep[f[u][i]] >= dep[v])
            u = f[u][i];
    if (u == v) return u;
    for (int i = k; i >= 0; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
void dfs2(int u, int fa)
{
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == fa) continue;
        dfs2(v, u);
        good[u] += good[v];
        bad[u] += bad[v];
    }
    if (!good[u] && bad[u]) ans++;
}
int main()
{
    cin >> n >> a;
    for (int i = 1; i <= n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    for (int i = 1; i <= a; i++)
    {
        int u, v;
        cin >> u >> v;
        int lc = lca(u, v);
        good[u]++, good[v]++, good[lc]--, good[f[lc][0]]--;
    }
    cin >> badx >> bady;
    int lc = lca(badx, bady);
    bad[badx]++, bad[bady]++, bad[lc]--, bad[f[lc][0]]--;
    dfs2(1, 0);
    cout << ans << endl;
    return 0;
}