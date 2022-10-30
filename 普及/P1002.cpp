#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m, cx, cy, a[25][25], f[25][25];

int main()
{
    cin >> n >> m >> cx >> cy;
    // 讲cx，cy周围的点都设置为-1
    for (int i = 0; i < 8; i++)
    {
        int x = cx + dx[i];
        int y = cy + dy[i];
        if (x >= 0 && x < n && y >= 0 && y < m)
            a[x][y] = -1;
    }
    // 求从(0,0)到(n,m)的方案数
    if (a[0][0] != -1)
        f[0][0] = 1;
    else
        f[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        if (a[0][i] == -1)
            f[0][i] = 0;
        else
            if (f[0][i-1] == 0)
                f[0][i] = 0;
            else
                f[0][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i][0] == -1)
            f[i][0] = 0;
        else
            if (f[i-1][0] == 0)
                f[i][0] = 0;
            else
                f[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == -1)
                f[i][j] = 0;
            else
                f[i][j] = f[i-1][j] + f[i][j-1];       
        }
    }

    // print f[i][j]
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    cout << f[n][m] << endl;
    return 0;
}