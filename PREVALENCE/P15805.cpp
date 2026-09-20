#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 105;
constexpr ll INF = 4e18;
constexpr ll mod = 1e9;
int n, m;
ll g[N][N], d[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    ll ans = 0;
    for (int l = 1; l <= n; l++)
    {
        memcpy(d, g, sizeof g);
        for (int r = l; r <= n; r++)
        {
            for (int i = l; i <= n; i++)
            {
                if (d[i][r] == INF) continue;
                for (int j = l; j <= n; j++)
                {
                    if (d[r][j] == INF) continue;
                    d[i][j] = min(d[i][j], d[i][r] + d[r][j]);
                }
            }
            // 当前 d 就是 G(l, r) 中的最短路
            for (int u = l; u <= r; u++)
            {
                for (int v = u+1; v <= r; v++)
                {
                    if (d[u][v] != INF)
                    {
                        ans += d[u][v] % mod;
                        ans %= mod;
                    }
                }
            }
        }
    }
    cout << ans % mod;
    return 0;
}