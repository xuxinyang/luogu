#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, dis[105][105];
ll mp[105][105];
double ans[105];
int main()
{
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        dis[x][y] = dis[y][x] = z;
        mp[x][y] = mp[y][x] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    mp[i][j] = mp[i][k] * mp[k][j];
                }
                else if (dis[i][j] == dis[i][k] + dis[k][j])
                {
                    mp[i][j] += mp[i][k] * mp[k][j];
                }
            }
        }
    }
    for (int v = 1; v <= n; v++)
    {
        for (int s = 1; s <= n; s++)
        {
            if (s == v) continue;
            for (int t = 1; t <= n; t++)
            {
                if (t == v || s == t) continue;
                if (dis[s][v] + dis[v][t] == dis[s][t])
                {
                    ll tmp = mp[s][v] * mp[v][t];
                    ans[v] += 1.0 * tmp / mp[s][t];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) 
        cout << fixed << setprecision(3) << ans[i] << "\n";
    return 0;
}