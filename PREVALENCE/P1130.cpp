#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int inf = INT_MAX;
int n, m;
int a[maxn][maxn], f[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i-1][j], j == 1 ? f[i-1][m]:f[i-1][j-1]) + a[i][j];
        }
    }
    int ans = inf;
    for (int i = 1; i <= m; i++) ans = min(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}