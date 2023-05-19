#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
const int maxm = 5e4+5;
struct Edge
{
    int to, next, cost;
};
Edge edges[maxm<<6];
int n, m, k, s, t, tot, head[maxn<<5], dis[maxn<<5];
bool vis[maxn<<5];
void add_edge(int u, int v, int w = 0)
{
    edges[++tot] = (Edge){v, head[u], w};
    head[u] = tot;
}
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (!vis[u])
        {
            vis[u] = 1;
            for (int i = head[u]; i; i = edges[i].next)
            {
                int to = edges[i].to;
                if (dis[to] > dis[u] + edges[i].cost)
                {
                    dis[to] = dis[u] + edges[i].cost;
                    pq.push(make_pair(dis[to], to)); 
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    cin >> s >> t;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
        for (int j = 1; j <= k; j++)
        {
            add_edge(u + (j-1) * n, v + j * n);
            add_edge(v + (j-1) * n, u + j * n);
            add_edge(u + j * n, v + j * n, w);
            add_edge(v + j * n, u + j * n, w);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        add_edge(t + (i-1) * n, t + i * n);
    }
    dijkstra(s);
    cout << dis[t + k * n];
    return 0;
}