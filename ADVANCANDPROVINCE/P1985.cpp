#include <bits/stdc++.h>
using namespace std;
int n, m, f[20][20], ans[20][20];
int tmp[20][20], a[20][20], minx = INT_MAX;
void dfs(int col)
{
    if (col > m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                tmp[i][j] = a[i][j];
        }
        for (int j = 1; j <= m; j++)
        {
            if (f[1][j])    // 处理第1行
            {
                tmp[1][j]^=1, tmp[2][j]^=1, tmp[1][j+1]^=1, tmp[1][j-1]^=1;
            }
        }
        for (int i = 2; i <= n; i++)    // 处理第2~n行
        {
            for (int j = 1; j <= m; j++)
            {
                if (tmp[i-1][j])
                {
                    f[i][j] = 1;
                    tmp[i][j]^=1, tmp[i][j-1]^=1, tmp[i][j+1]^=1, tmp[i+1][j]^=1, tmp[i-1][j] ^= 1;
                }
                else f[i][j] = 0;
                if (tmp[i-1][j]) return;
            }
        }
        bool flag = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (tmp[i][j]) {flag = 1; break;}
            }
        }
        if (!flag)
        {
            int s = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (f[i][j]) s++;
                }
            }
            if (s >= minx) return;
            minx = s;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                    ans[i][j] = f[i][j];
            }
        }
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        f[1][col] = i, dfs(col+1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    dfs(1);
    if (minx == INT_MAX) cout << "IMPOSSIBLE";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}