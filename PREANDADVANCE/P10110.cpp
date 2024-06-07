#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 2e5+5;
const int inf = 0x3f3f3f3f;
int n, m, a, b, w[maxn], tot, head[maxn], dist[maxn];
bool vis[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
struct Edge
{
    int to, nxt;
};
Edge edges[maxm];
void add(int u, int v)
{
    edges[++tot] = Edge{v, head[u]};
    head[u] = tot;
}
void dijkstra(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[a] = 0;
    pq.push({dist[a], a});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = edges[i].nxt)
        {
            int v = edges[i].to;
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    dijkstra(a);
    if (dist[b] == inf) cout << "No solution";
    else cout << w[b]-w[a]+dist[b];
    return 0;
}