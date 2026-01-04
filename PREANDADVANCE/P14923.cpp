#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, a, b, c[N];
vector<array<int, 2>> ve[N];
ll dist[N], ans;
priority_queue<array<ll, 2>> q;
int main()
{
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ve[v].push_back({u, w});
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[b] = 0;
    q.push({-dist[b], b});
    while (!q.empty())
    {
        auto cur = q.top();
        q.pop();
        if (dist[cur[1]] != -cur[0]) continue;
        int u = cur[1];
        for (auto it: ve[u])
        {
            int v = it[0], w = it[1];
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < dist[a]) ans += c[i];
    }
    cout << ans;
    return 0;
}