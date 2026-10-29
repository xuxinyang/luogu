#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e4+5;
constexpr int LOG = 20;

int n, k;
int head[N], to[N<<1], nxt[N<<1], tot;
int dep[N], fa[N][LOG], d[N];
int q[N];
void add(int u, int v)
{
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
void bfs()
{
    int l = 1, r = 1;
    q[1] = 1;
    dep[1] = 1;
    while (l <= r) 
    {
        int u = q[l++];
        for (int i = head[u]; i ; i = nxt[i])
        {
            int v = to[i];
            if (v == fa[u][0]) continue;
            dep[v] = dep[u] + 1;
            fa[v][0] = u;
            for (int j = 1; j < LOG; j++)
            {
                fa[v][j] = fa[fa[v][j-1]][j-1];
            }
            q[++r] = v;
        }
    }
}
int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    int x = dep[u] - dep[v];
    for (int j = LOG-1; j >= 0; j--)
    {
        if ((x>>j)&1) u = fa[u][j];
    }
    if (u == v) return u;
    for (int j = LOG-1; j >= 0; j--)
    {
        if (fa[u][j] != fa[v][j]) u = fa[u][j], v = fa[v][j];
    }
    return fa[u][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    bfs();
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        int p = lca(u, v);
        d[u]++, d[v]++, d[p]--;
        if (fa[p][0] != 0) d[fa[p][0]]--;
    }
    for (int i = n; i >= 2; i--)
    {
        int u = q[i];
        d[fa[u][0]] += d[u];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) ans = max(ans, d[i]);
    cout << ans;
    return 0;
}