#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = INT_MAX;

int n, a[maxn], dp[maxn][maxn];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int i = 1; i < n; i++) dp[i][i+1] = 1 + (a[i] != a[i+1]);
    for (int d = 3; d <= n; d++)
    {
        for (int i = 1; i + d - 1 <= n; i++)
        {
            int l = i, r = i + d - 1;
            if (a[l] == a[r]) dp[l][r] = dp[l+1][r-1];
            for (int j = l; j < r; j++)
                dp[l][r] = min(dp[l][r], dp[l][j] + dp[j+1][r]);
        }
    }
    cout << dp[1][n];
    return 0;
}