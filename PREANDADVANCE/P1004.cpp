#include <bits/stdc++.h>
using namespace std;
int f[12][12][12][12], a[12][12], n;

int main()
{
    cin >> n;
    int x, y, z;
    while (cin >> x >> y >> z && x+y+z!=0) a[x][y] = z;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int p = 1; p <= n; p++)
            {
                for (int q = 1; q <= n; q++)
                {
                    f[i][j][p][q] = max(
                        max(f[i-1][j][p-1][q], f[i-1][j][p][q-1]),
                        max(f[i][j-1][p-1][q], f[i][j-1][p][q-1])) + a[i][j] + a[p][q];
                    if (i == p && j == q) f[i][j][p][q] -= a[i][j];
                }
            }
        }
    }
    cout << f[n][n][n][n];
    return 0;
}