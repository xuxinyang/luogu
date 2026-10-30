#include <bits/stdc++.h>
using namespace std;
#define pli pair<int, int>
#define ll long long
constexpr int N = 1e3+5;
vector<array<int, 2>> ve[N], re[N];
int dis1[N], disn[N], n, m;
void dijkstra(int dis[], int s, vector<array<int, 2>> g[])
{
    dis[s] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        int w = pq.top().first, u = pq.top().second;
        pq.pop();
        if (w != dis[u]) continue;
        for (auto e : g[u])
        {
            int v = e[0], w = e[1];
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        re[v].push_back({u, w});
    }
    memset(dis1, 0x3f, sizeof dis1);
    memset(disn, 0x3f, sizeof disn);
    dijkstra(dis1, 1, ve);
    dijkstra(disn, 1, re);
    ll ans = 0;
    for (int i = 2; i <= n; i++) ans += dis1[i]+disn[i];
    cout << ans;
    return 0;
}