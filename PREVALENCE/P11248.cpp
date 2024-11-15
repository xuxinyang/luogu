#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int maxk = 305;
int t, n, m, x, f[maxn][maxn][maxk];
char c[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n >> m >> x;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) cin >> c[i][j];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 0; k <= x; k++)
                {
                    f[i][j][k] = max(f[i-1][j][k], f[i][j-1][k]) + (c[i][j] == '1');
                    if(c[i][j] == '?' && k) f[i][j][k] = max(f[i][j][k], max(f[i-1][j][k-1], f[i][j-1][k-1])+1);
                }
            }
        }
        cout << f[n][m][x] << "\n";
    }
    return 0;
}