#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e6+5;
int n, m, q, head[maxn], cost[maxn], tot, cnt;
bool flag[maxn];
struct Edge
{
    int to, w, next;
};
Edge edges[maxm];
priority_queue<pair<int, int> > pq;
void add(int u, int v, int w)
{
    edges[++tot] = (Edge){v, w, head[u]};
    head[u] = tot;
}
void dijkstra(int u)
{
    memset(cost, 0x7f, sizeof(cost));
    memset(flag, 0, sizeof(flag));
    cost[u] = 0;
    pq.push(make_pair(0, u));
    while (pq.size())
    {
        int u = pq.top().second;
        pq.pop();
        if (flag[u]) continue;
        flag[u] = 1;
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            int w = edges[i].w;
            if (cost[v] >= cost[u] ^ w || cnt == m)
            {
                cost[v] = cost[u] ^ w;
                pq.push(make_pair(-cost[v], v));
            }
        }
    }
}
int main()
{
    cin >> n >> m >> q;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
        if (w <= 1) cnt++;
    }
    dijkstra(1);
    while (q--)
    {
        cin >> u >> v;
        cout << (cost[u] ^ cost[v]) << "\n";
    }
    return 0;
}