#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+5;
int n, m, a[maxn], diff[maxn];
int head[maxn], cnt, fa[maxn][25], dep[maxn];
struct Edge
{
    int to, from, next;
};
Edge edges[maxn<<1];
void add(int u, int v)
{
    edges[++cnt] = Edge{v, u, head[u]};
    head[u] = cnt;
}
void dfs(int u, int f)
{
    fa[u][0] = f, dep[u] = dep[f] + 1;
    for (int i = 1; i <= 24; i++)
        fa[u][i] = fa[fa[u][i-1]][i-1];
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == f) continue;
        dfs(v, u);
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 24; i >= 0; i--)
    {
        if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 24; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}
void ask(int u, int f)
{
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == f) continue;
        ask(v, u);
        diff[u] += diff[v];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n-1; i++)
    {
        int u = a[i], v = a[i+1];
        int t = lca(u, v);
        diff[fa[t][0]] -= 1;
        diff[t] -= 1;
        diff[u] += 1;
        diff[v] += 1;
    }
    ask(1, 0);
    for (int i = 2; i <= n; i++) diff[a[i]]--;
    for (int i = 1; i <= n; i++) cout << diff[i] << "\n";
    return 0;
}