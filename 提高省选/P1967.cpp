#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 5e4+5;
const int maxg = 1e5+5;
const int inf = INT_MAX;
struct Edge1
{
    int x, y, dis;
}edges1[maxm];
struct Edge2
{
    int to, next, w;
}edges2[maxg];
int n, m, x, y, q, tot, head[maxn], deep[maxn], fa[maxn], f[maxn][21], w[maxn][21];
bool vis[maxn];
void addEdge(int u, int v, int w)
{
    edges2[++tot].to = v;
    edges2[tot].w = w;
    edges2[tot].next = head[u];
    head[u] = tot;
}
bool cmp(Edge1 x, Edge1 y)
{
    return x.dis > y.dis;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fx] = fy;
}
void kruskal()
{
    sort(edges1 + 1, edges1 + m + 1, cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        if (find(edges1[i].x) != find(edges1[i].y))
        {
            merge(edges1[i].x, edges1[i].y);
            addEdge(edges1[i].x, edges1[i].y, edges1[i].dis);
            addEdge(edges1[i].y, edges1[i].x, edges1[i].dis);
        }
    }
}
void dfs(int u)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = edges2[i].next)
    {
        int to = edges2[i].to;
        if (vis[to]) continue;
        deep[to] = deep[u] + 1;
        f[to][0] = u;
        w[to][0] = edges2[i].w;
        dfs(to);
    }
    return;
}
int lca(int x, int y)
{
    if (find(x) != find(y)) return -1;
    int ans = inf;
    if (deep[x] > deep[y]) swap(x, y);
    for (int i = 20; i >= 0; i--)
    {
        if (deep[f[y][i]] >= deep[x])
        {
            ans = min(ans, w[y][i]);
            y = f[y][i];
        }
    }
    if (x == y) return ans;
    for (int i = 20; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            ans = min(ans, min(w[x][i], w[y][i]));
            x = f[x][i], y = f[y][i];
        }
    }
    ans = min(ans, min(w[x][0], w[y][0]));
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> edges1[i].x >> edges1[i].y >> edges1[i].dis;
    kruskal();
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            deep[i] = 1;
            dfs(i);
            f[i][0] = i;
            w[i][0] = inf;
        }
    }
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[j][i] = f[f[j][i-1]][i-1];
            w[j][i] = min(w[j][i-1], w[f[j][i-1]][i-1]);
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
    return 0;
}