#include <bits/stdc++.h>
using namespace std;
#define ll long long
// 区间dp
// dp[l][r] 表示保留 a[l-1]和a[r+1] 的前提下，将区间 [l,r] 全部删除，能够获得的最大分数
ll n, a[105], dp[105][105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l <= n-len+1; l++)
        {
            int r = l + len - 1;
            for (int k = l; k <= r; k++)
            {
                dp[l][r] = max(dp[l][r], dp[l][k-1]+dp[k+1][r] + a[l-1]+a[r+1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}