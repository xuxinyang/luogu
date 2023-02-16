#include <bits/stdc++.h>
using namespace std;
int dp[305][305], len, a[305], n, sum[305];
int main()
{
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        dp[i][i] = 0;
    }
    for (int d = 2; d <= n; d++)
    {
        for (int i = 1; i <= n - d + 1; i++)
        {
            int j = i + d - 1;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    cout << dp[1][n];
}