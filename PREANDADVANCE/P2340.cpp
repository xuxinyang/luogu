#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
const int maxf = 8e5+5;
const int offset = 4e5;
int n, s[maxn], f[maxn], dp[maxf], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> f[i];
    }
    memset(dp, 0xc0, sizeof(dp));
    dp[400000] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] >= 0)
            for (int j = 800000; j >= s[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-s[i]] + f[i]);
            }
        else
            for (int j = 0; j <= 800000 + s[i]; j++)
            {
                dp[j] = max(dp[j], dp[j-s[i]] + f[i]);
            }
    }
    for (int i = 400000; i <= 800000; i++)
    {
        if (dp[i] > 0)
            ans = max(ans, dp[i] + i - 400000);
    }
    cout << ans;
    return 0;
}