#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
char c;
int sum[15][15];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(c - '0');
        }
    }
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
                    //r*c == 2*(sum[i+r-1][j+c-1]-sum[i+r-1][j-1]-sum[i-1][j+c-1]+sum[i-1][j-1])
                    if (r*c == 2*(sum[i+r-1][j+c-1]-sum[i+r-1][j-1]-sum[i-1][j+c-1]+sum[i-1][j-1]))
                        ans = max(ans, r*c);
                }
            }
        }
    }
    cout << ans;
    return 0;
}