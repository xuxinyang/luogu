#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int n, m, mp[105][105], ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(mp, 0x3f, sizeof(mp));
    for (int i = 1; i <= n; i++) mp[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        mp[x][y] = mp[y][x] = z;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    ans = inf;
    for (int x = 1; x < n; x++)
    {
        for (int y = x + 1; y <= n; y++)
        {
            int res = 0;
            // 再跑一遍Floyd
            for (int i = 1; i < n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    res += min(mp[i][j], min(mp[i][x] + mp[y][j], mp[i][y] + mp[x][j]));
                }
            }
            ans = min(ans, res);
        }
    }
    cout << ans;
    return 0;
}