#include <bits/stdc++.h>
using namespace std;
constexpr int N = 505;
constexpr int INF = 1e9;
int n, m, q;
int f[N][N];
struct Edge{
    int to, u, w;
};
vector<Edge> ve[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, l, t;
        cin >> u >> v >> l >> t;
        ve[v].push_back({u, l, t});
    }
    for (int y = 1; y <= n; y++)
    {
        for (int i = 1; i <= n; i++)
            f[i][y] = -1;
        priority_queue<pair<int, int>> q;
        f[y][y] = INF;
        q.push({INF, y});
        while (!q.empty())
        {
            int tim = q.top().first;
            int v = q.top().second;
            q.pop();
            if (tim != f[v][y]) continue;
            for (auto e : ve[v])
            {
                int u = e.to;
                int nt = min(e.u, tim-e.w);
                if (nt < 0) continue;
                if (nt > f[u][y])
                {
                    f[u][y] = nt;
                    q.push({nt, u});
                }
            }
        }
    }
    while (q--)
    {
        int x, y, s;
        cin >> x >> y >> s;
        if (s <= f[x][y]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}