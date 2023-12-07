#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8+5;
const int maxn = 1e2+5;
const int maxm = 5e3+5;
int n, m, mp[maxn][maxn], dis[maxn][maxn], ans;
int main()
{
    int u, v, d;
    cin >> n >> m;
    ans = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j) mp[i][j] = dis[j][i] = inf;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> d;
        dis[u][v] = min(dis[u][v], d);
        dis[v][u] = min(dis[v][u], d);
        mp[u][v] = min(mp[u][v], d);
        mp[v][u] = min(mp[v][u], d);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i+1; j < k; j++)
            {
                ans = min(ans, dis[i][j] + mp[i][k] + mp[k][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j], dis[j][i] = dis[i][j];
            }
        }
    }
    if (ans != inf) cout << ans;
    else cout << "No solution.";
    return 0;
}