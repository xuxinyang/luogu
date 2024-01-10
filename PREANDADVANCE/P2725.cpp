#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
const int inf = 1e9;
int a[55], dp[maxn], k, n, m;
int main()
{
    cin >> k >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0] = 0;
    int i = 0;
    while (dp[i] <= k)
    {
        i++;
        dp[i] = inf;
        for (int j = 1; j <= n && a[j] <= i; j++)
        {
            if (dp[i-a[j]] + 1 < dp[i]) dp[i] = dp[i-a[j]]+1;
        }
    }
    cout << i-1;
    return 0;
}