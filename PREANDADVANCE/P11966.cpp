#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
const int maxm = 2e5+5;
int n, m, s, q, tot, head[maxn];
ll dis[maxn];
bool vis[maxn];
struct Edge
{
    ll to, next, w;
} edges[maxm<<1];
void add(ll u, ll v, ll w)
{
    edges[++tot] = {v, head[u], w};
    head[u] = tot;
}
void dijikstra()
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i; i = edges[i].next)
        {
            ll v = edges[i].to, w = edges[i].w;
            if (dis[v] > d + w)
            {
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    dijikstra();
    while (q--)
    {
        int t;
        cin >> t;
        cout << dis[t] << "\n";
    }
    return 0;
}