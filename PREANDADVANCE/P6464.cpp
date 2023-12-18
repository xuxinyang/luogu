#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int n, m, mp[105][105], ans, tmp[105][105];
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
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y < x; y++)
        {
            if (mp[x][y])
            {
                // 置空
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        tmp[i][j] = mp[i][j];
                    }
                }
                // x--y设置为0
                tmp[x][y] = tmp[y][x] = 0;
                // 再跑一遍Floyd
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        tmp[i][j] = min(tmp[i][j], tmp[i][x] + tmp[x][j]);
                    }
                }
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        tmp[i][j] = min(tmp[i][j], tmp[i][y] + tmp[y][j]);
                    }
                }
                int res = 0;
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j < i; j++)
                    {
                        res += tmp[i][j];
                    }
                }
                ans = min(ans, res);
            }
        }
    }
    cout << ans;
    return 0;
}