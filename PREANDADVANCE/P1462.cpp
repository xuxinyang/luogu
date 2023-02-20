#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4+5;
const int maxm = 1e5+5;
const ll inf = LLONG_MAX;
int n, m, b, u, v, w;
struct Priority
{
    int id, dis;
    Priority() {}
    Priority(int _id, ll _dis)
    {
        id = _id, dis = _dis;
    }
    bool operator < (const Priority &node) const
    {
        return dis > node.dis;
    }
};
priority_queue<Priority> pq;
int cnt, head[maxn], f[maxn];
ll dist[maxn];
bool vis[maxn];
struct Edge
{
    int to, next;
    ll w;
};
Edge edges[maxm];
void add(int u, int v, ll w)
{
    edges[++cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}
void dijkstra(int x)
{
    while (!pq.empty()) pq.pop();   // 清空队列
    for (int i = 1; i <= n; i++)
    {
        dist[i] = inf;
        vis[i] = 0;
    }
    dist[1] = 0;
    Priority node = Priority(1, dist[1]);
    pq.push(node);
    while (!pq.empty())
    {
        Priority node = pq.top();
        pq.pop();
        int u = node.id;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (f[v] > x) continue;
            if (dist[v] > dist[u] + edges[i].w)
            {
                dist[v] = dist[u] + edges[i].w;
                pq.push((Priority){v, dist[v]});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> b;
    int l = 0, r = 0, mid;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        r = max(r, f[i]);
    }
    l = max(f[1], f[n]);
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    while (l < r)
    {
        mid = (l + r) >> 1;
        dijkstra(mid);
        if (dist[n] > b) l = mid + 1;
        else r = mid;
    }
    dijkstra(l);
    if (dist[n] > b) cout << "AFK\n";
    else cout << l << "\n";
    return 0;
}