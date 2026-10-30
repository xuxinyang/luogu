#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
constexpr int N = 1e5+1e4;
constexpr ll INF = (1LL<<60);
struct Edge {
    int v, w;
};
vector<Edge> ve[N];
ll dis[N];
int n, m, k, s, t;
void dijkstra()
{
    int num = (k + 1) * n;
    fill(dis, dis+num, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dis[u]) continue;
        for (auto e : ve[u])
        {
            int v = e.v, w = e.w;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // 付费乘坐，免费次数不变，在同一层移动
        for (int j = 0; j <= k; j++)
        {
            int x = j*n+u, y = j*n+v;
            ve[x].push_back({y, w});
            ve[y].push_back({x, w});
        }
        // 免费乘坐，免费次数加1，进入下一层
        for (int j = 0; j < k; j++)
        {
            ve[j*n+u].push_back({(j+1)*n+v, 0});
            ve[j*n+v].push_back({(j+1)*n+u, 0});
        }
    }
    dijkstra();
    ll ans = INF;
    for (int j = 0; j <= k; j++)
    {
        ans = min(ans, dis[j*n+t]);
    }
    cout << ans;
    return 0;
}