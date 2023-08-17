#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int inf = INT_MAX;
int n, k, f[maxn], a[maxn], dp[maxn<<7], ans;
void dfs(int x)
{
    if (x == k+1)
    {
        memset(dp, 0, sizeof(dp));
        int i = 0;
        while (dp[i] <= n)
        {
            i++;
            dp[i] = inf;
            for (int j = 1; j <= k && i-f[j] >= 0; j++)
            {
                dp[i] = min(dp[i], dp[i-f[j]]+1);
            }
        }
        if (i-1 > ans)  // 更新最大值
        {
            for (int j = 1; j <= k; j++)
            {
                a[j] = f[j];
                ans = i-1;
            }
        }
        return;
    }
    for (int i = f[x-1]+1; i <= f[x-1]*n+1; i++)
    {
        f[x] = i;
        dfs(x+1);
    }
}
int main()
{
    cin >> n >> k;
    f[1] = 1;
    dfs(2);
    for (int i = 1; i <= k; i++) cout << a[i] << " ";
    cout << "\n";
    cout << "MAX=" << ans;
    return 0;
}