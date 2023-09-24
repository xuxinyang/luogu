#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, l, r, a[maxn], dp[maxn<<1], ans, f[maxn];
queue<int> q;
int main()
{
    cin >> n >> l >> r;
    for (int i = 1; i <= n+1; i++) cin >> a[i-1];
    for (int i = 0; i <= l; i++) dp[i] = 0;
    for (int i = l+1; i <= n + r; i++)
    {
        int tmp = 0;
        for (int j = max(i-r, 0); j <= i-l; j++)
        {
            tmp = max(tmp, dp[j]);
        }
        dp[i] = tmp + a[i];
    }
    for (int i = n; i <= n + r; i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}