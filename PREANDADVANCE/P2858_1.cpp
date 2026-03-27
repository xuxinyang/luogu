#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
int n, dp[N][N], v[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i+len-1<=n; i++)
        {
            int j = i+len-1;
            dp[i][j] = max(dp[i+1][j]+v[i]*(n-len+1), dp[i][j-1]+v[j]*(n-len+1));
        }
    }
    cout << dp[1][n];
    return 0;
}