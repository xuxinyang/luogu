#include <bits/stdc++.h>
using namespace std;
int m, n, k, a[105][105], f[105][105][105];
int main()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    f[0][1][1] = f[1][0][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int w = 0; w < k; w++)
            {
                if (f[i-1][j][w] == 1) f[i][j][w*a[i][j]%k] = 1;
                if (f[i][j-1][w] == 1) f[i][j][w*a[i][j]%k] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < k; i++) if(f[m][n][i]) sum++;
    cout << sum << endl;
    for (int i = 0; i < k; i++)
        if (f[m][n][i]) cout << i << " ";
    return 0;
}