#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
const ll inf = 1e18;
ll n, a[maxn], b[maxn], dp[maxn], sum, ans, maxx, minx;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        b[i] = -a[i];
    }
    maxx = -inf, minx = -inf;
    // 环上最大子段和
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i-1]+a[i], a[i]);
        maxx = max(maxx, dp[i]);
    }
    // 环上最小子段和
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i-1]+b[i], b[i]);
        minx = max(minx, dp[i]);
    }
    // 需要保证至少选一个，即如果都为负值，选最大的负数
    ans = max(maxx, sum+minx);
    if (ans == 0) cout << maxx;
    else cout << ans;
    return 0;
}