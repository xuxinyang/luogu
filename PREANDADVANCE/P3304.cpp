#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, head[maxn], tot, dist[maxn], k, maxdist, ans;
bool vis[maxn];
map<pair<int, int>, int> mp;
struct Edge
{
    int to, next, w;
};
Edge edges[maxn<<1];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, head[u], w};
    head[u] = tot;
};
void dfs1(int u)
{
    for (int i = head[u]; i ; i = edges[i].next)
    {
        int to = edges[i].to;
        if (!vis[to])
        {
            vis[to] = true;
            dist[to] = dist[u] + edges[i].w;
            dfs(to);
        }
    }
}
void dfs2(int u)
{
    for (int i = head[u]; i ; i = edges[i].next)
    {
        int to = edges[i].to;
        if (!vis[to])
        {
            vis[to] = true;
            dist[to] = dist[u] + edges[i].w;
            dfs1(to);
        }
    }
}
int main()
{
    int u, v, w;
    cin >> n;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    dfs1(1);
    for (int i = 1; i <= n; i++)
    {
        if (maxdist < dist[i])
        {
            maxdist = dist[i];
            k = i;
        }
    }
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    vis[k] = 1;
    dfs1(k);
    for (int i = 1; i <= n; i++)
    {
        if (maxdist < dist[i])
        {
            maxdist = dist[i];
            k = i;
        }
    }
    cout << maxdist << endl;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == maxdist)
        {
            memset(vis, 0, sizeof(vis));
            dfs2(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}