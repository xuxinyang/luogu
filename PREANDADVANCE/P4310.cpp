#include <bits/stdc++.h>
using namespace std;
// dp[i]表示枚举到当前项第i位为1的最大子序列长度
int dp[32], n, x, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k = 1;
        cin >> x;
        for (int j = 0; j <= 30; j++)
        {
            if ((1<<j)&x) k= max(dp[j]+1, k);
        }
        for (int j = 0; j <= 30; j++)
        {
            if ((1<<j)&x) dp[j] = max(dp[j], k);
        }
        ans = max(ans, k);
    }
    cout << ans;
    return 0;
}