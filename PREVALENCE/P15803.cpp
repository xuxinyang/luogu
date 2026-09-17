#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 5e3+5;
constexpr int M = 5e3+5;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
vector<array<ll, 3>> ve[N];
int n, m;
ll dist1[N], distn[N], ans = inf;
struct Edge{
    ll u, v, w, b;
} e[M];
void dijkstra(int s, int B, ll dist[])
{
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, s});
    while (!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();
        if (d != dist[u]) continue;
        for (auto [v, w, b] : ve[u])
        {
            if (b > B) continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w, b;
        cin >> u >> v >> w >> b;
        ve[u].push_back({v, w, b});
        ve[v].push_back({u, w, b});
        e[i] = {u, v, w, b};
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    sort(e+1, e+m+1, [](Edge A, Edge B){
        return A.b < B.b;
    });
    for (int i = 1; i <= m; )
    {
        int j = i;
        ll B = e[i].b;
        while (j <= m && e[j].b == B) j++;
        dijkstra(1, B, dist1);
        dijkstra(n, B, distn);
        for (int k = i; k < j; k++)
        {
            int u = e[k].u, v = e[k].v;
            if (dist1[u] != inf && distn[v] != inf)
                ans = min(ans, dist1[u] + distn[v]);
            if (dist1[v] != inf && distn[u] != inf)
                ans = min(ans, dist1[v] + distn[u]);
        }
        i = j;
    }
    if (ans == inf) cout << -1;
    else cout << ans;
    return 0;
}