#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int n, m, u, v, w, c, a[maxn], ans[maxn];
int in[maxn];
int tot, head[maxn];
queue<int> q;
struct Edge
{
    int to, w, next;
};
Edge edges[maxm];
void add(int u, int v, int w)
{
    edges[++tot] = (Edge){v, w, head[u]};
    head[u] = tot;
}
void topo_sort()
{
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) q.push(i);
        ans[i] = a[i];
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            ans[v] = max(ans[v], ans[u] + edges[i].w);
            if (--in[v] == 0) q.push(v);
        }
    }
}
int main()
{
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= c; i++)
    {
        cin >> u >> v >> w;
        in[v]++;
        add(u, v, w);
    }
    topo_sort();
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}