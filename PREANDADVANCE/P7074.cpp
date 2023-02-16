#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, a[1005][1005];
ll f[1005][1005][2];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[j][i];
        }
    }
    memset(f, 0xcc, sizeof(f));
    f[1][1][0] = f[1][1][1] = a[1][1];
    swap(n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j =1; j <= m; j++)
        {
            if (i != 1) // 向下转移
            {
                f[i][j][0] = max(f[i][j][0], max(f[i-1][j][0], f[i-1][j][1]) + a[i][j]);
                f[i][j][1] = max(f[i][j][1], max(f[i-1][j][0], f[i-1][j][1]) + a[i][j]);
            }
            if (j != 1)  f[i][j][0] = max(f[i][j][0], f[i][j-1][0] + a[i][j]);  // 向右转移
        }
        for (int j = m - 1; j >= 1; j--)
        {
            f[i][j][1] = max(f[i][j][1], f[i][j+1][1] + a[i][j]);   // 向左转移
        }
    }
    cout << max(f[n][m][0], f[n][m][1]) << endl;
    return 0;
}