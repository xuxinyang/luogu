#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 10;
int f[105][105][15], g[105][105][15];
int n, m, a[105], sum[105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int i = 1; i <= n*2; i++) sum[i] = sum[i-1]+a[i];
    for (int i = 1; i <= 2*n; i++)
        for (int j = i; j <= 2*n; j++)
            f[i][j][1] = g[i][j][1] = ((sum[j]-sum[i-1])%mod + mod) % mod;
    for (int i = 2; i <= m; i++)
        for (int l = 1; l <= n*2; l++)
            for (int r = l+i-1; r <= 2*n; r++) f[l][r][i] = inf;
    for (int i = 2; i <= m; i++)
    {
        for (int l = 1; l <= 2*n; l++)
        {
            for (int r = l+i-1; r <= 2*n; r++)
            {
                for (int k = l+i-2; k < r; k++)
                {
                    f[l][r][i] = min(f[l][r][i], f[l][k][i-1]*(((sum[r]-sum[k])%10 + 10)%mod));
                    g[l][r][i] = max(g[l][r][i], g[l][k][i-1]*(((sum[r]-sum[k])%10 + 10)%mod));
                }
            }
        }
    }
    int maxx = 0, minx = inf;
    for (int i = 1; i <= n; i++)
        maxx = max(maxx, g[i][i+n-1][m]),
        minx = min(minx, f[i][i+n-1][m]);
    cout << minx << "\n" << maxx;
    return 0;
}