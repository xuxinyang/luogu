#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, m, k, x, f[maxn][maxn];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            f[x][j] = 1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int ans = 0;
        for (int j = 1; j <= m; j++)
        {
            if (f[i][j]) ans++;
        }
        cout << ans << " ";
    }
    return 0;
}