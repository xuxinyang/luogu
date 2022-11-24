#include <bits/stdc++.h>
using namespace std;
int a[55][55], f[55][55][55][55], m, n;
int Max(int a, int b, int c, int d)
{
    return max(max(a, b), max(c, d));
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k < i; k++)
            {
                for (int l = j+1; l <= n; l++)
                {
                    f[i][j][k][l] = Max(f[i][j-1][k-1][l], f[i-1][j][k][l-1], f[i-1][j][k-1][l], f[i][j-1][k][l-1]) + a[i][j] + a[k][l];
                    // cout << i << " " << j << " " << k << " " << l << " " << f[i][j][k][l] << "\n";
                }
            }
        }
    }
    cout << f[m][n-1][m-1][n] << "\n";
    return 0;
}