#include <bits/stdc++.h>
using namespace std;
int n, a[45], dp[45][1005]; // dp[i][j]表示前i个数凑成j的方案数
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) a[i] = i;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n*(n+1)/2; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= a[i]) dp[i][j] = dp[i][j] + dp[i-1][j-a[i]];
        }
    }
    if (n*(n+1)%4 == 0) cout << dp[n][n*(n+1)/4];
    else cout << 0;
    return 0;
}