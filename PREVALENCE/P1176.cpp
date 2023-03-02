#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int mod = 1e5+3;
int n, m, a[maxn][maxn], f[maxn][maxn];
int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[x][y] = 1;
    }
    f[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j]) f[i][j] = 0;
            else f[i][j] = (f[i-1][j] + f[i][j-1]) % mod;
        }
    }
    cout << f[n][n];
    return 0;
}