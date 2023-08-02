#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
const int maxf = 1e3+5;
const int mod = 1e8;
int n, f, a[maxn], dp[maxn][maxf];
int main()
{
    cin >> n >> f;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= f;
    }
    for (int i = 1; i <= n; i++) dp[i][a[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= f-1; j++)
        {
            dp[i][j] = ((dp[i][j] + dp[i-1][j]) % mod + dp[i-1][(j-a[i]+f)%f]) % mod;
        }
    }
    cout << dp[n][0];
    return 0;
}