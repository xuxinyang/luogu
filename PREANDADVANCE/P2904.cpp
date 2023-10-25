#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, m, a[maxn], dp[maxn];
int main()
{
    cin >> n >> m;
    a[0] = 2 * m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i] = a[i];
        for (int j = 0; j < i; j++)
        {
            dp[i] = min(dp[i], dp[j]+a[i-j]);
        }
    }
    cout << dp[n] - m;
    return 0;
}