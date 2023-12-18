#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e4+5;
int n, m, a[maxm], mp[105][105], ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    memset(mp, 0x3f, sizeof(mp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
        }
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
    for (int i = 1; i < m; i++)
    {
        ans += mp[a[i]][a[i+1]];
    }
    cout << ans;
    return 0;
}