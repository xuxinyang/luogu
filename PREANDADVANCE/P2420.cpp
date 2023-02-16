#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, tot, head[maxn], dis[maxn];
bool vis[maxn];
struct Edge
{
    int to, w, next;
};
Edge edges[maxn<<1];
void add(int u, int v, int w)
{
    edges[++tot].to = v;
    edges[tot].w = w;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u, int w)
{
    dis[u] = w, vis[u] = 1;
    for (int i = head[u]; i; i = edges[i].next)
    {
        if (!vis[edges[i].to])
            dfs(edges[i].to, w ^ edges[i].w);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    dfs(1, 0);
    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        cout << (dis[u] ^ dis[v]) << "\n";
    }
    return 0;
}