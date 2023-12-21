#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 105;
int n, m, lowcost[maxn], ans, mp[maxn][maxn];
bool s[maxn];
int main()
{
    cin >> n >> m;
    int u, v, w;
    memset(mp, 0x3f, sizeof(mp));
    for (int i = 1; i <= n; i++) mp[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = w;
        ans += w;
    }
    memset(lowcost, 0x3f, sizeof(lowcost));
    s[1] = 1;
    lowcost[1] = 0;
    for (int i = 2; i <= n; i++) lowcost[i] = mp[1][i];
    for (int i = 1; i < n; i++)
    {
        int tmp = inf;
        int t = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!s[j] && lowcost[j] < tmp)
            {
                t = j, tmp = lowcost[j];
            }
        }
        if (t == 1) break;
        s[t] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!s[j] && mp[t][j] < lowcost[j])
                lowcost[j] = mp[t][j];
        }
    }
    cout << ans - accumulate(lowcost + 1, lowcost + n + 1, 0);
    return 0;
}