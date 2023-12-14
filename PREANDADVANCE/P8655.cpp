#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct Edge
{
    int to, next;
};
Edge edges[maxn<<1];
int n, tot, head[maxn], fa[maxn];
int inc[maxn], cn;
bool vis[maxn], path[maxn];
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
bool dfs(int u)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v != fa[u])
        {
            fa[v] = u;
            if (vis[v])
            {
                int p = u;
                while (1)
                {
                    inc[p] = 1, p = fa[p];
                    if (p == u) break;
                }
                return 1;
            }
            else
                if (dfs(v)) return 1;
        }
    }
    return 0;
}
int main()
{
    int u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (inc[i]) cout << i << " ";
    }
    return 0;
}