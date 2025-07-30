#include <bits/stdc++.h>
using namespace std;
const int W = 1e5+5;
const int N = 105;
int n, dp[W];
int main()
{
    cin >> n;
    memset(dp, 0xc0, sizeof dp);
    dp[W/2] = 0; 
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        int v = a+b, m = a-b;
        if (m <= 0)
            for (int j = -m; j < W; j++)
            {
                dp[j+m] = max(dp[j+m], dp[j]+v);
            }
        else
            for (int j = W-m-1; j; j--)
                dp[j+m] = max(dp[j+m], dp[j]+v);
    }
    cout << dp[W/2];
    return 0;
}