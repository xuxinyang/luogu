#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e4+5;
ll n, m, k, a[N], dp[N];    // dp[i] 表示前i个橙子装进箱子的最小花费
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll maxx = a[i], minx = a[i];
        for (int j = i-1; j >= max(0LL, i-m); j--)
        {
            dp[i] = min(dp[i], dp[j]+k+(i-j)*(maxx-minx));
            maxx = max(maxx, a[j]), minx = min(minx, a[j]);
        }
    }
    cout << dp[n];
    return 0;
}