#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
char c;
int sum[105][105];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(c - '0');
        }
    }
    ans = INT_MAX;
    for (int r = 1; r <= n; r++)    // 枚举矩形的高
    {
        for (int c = 1; c <= m; c++)  // 枚举矩形的宽
        {
            // 枚举 (r,c) 矩形的所有情况
            for (int i = 1; i <= n-r+1; i++)
            {
                for (int j = 1; j <= m-c+1; j++)
                {
                    // 验证是否满足要求，即
                    if (k <= (sum[i+r-1][j+c-1]-sum[i+r-1][j-1]-sum[i-1][j+c-1]+sum[i-1][j-1]))
                    {
                        ans = min(r*c, ans);
                    }
                }
            }
        }
    }
    if (ans == INT_MAX) cout << 0;
    else cout << ans;
    return 0;
}