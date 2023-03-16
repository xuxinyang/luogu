#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int t[n + 1][m + 1];
    int dp[m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &t[i][j]);
        }
    }
    dp[0] = 0;
    int maxn;
    for (int j = 1; j <= m; j++)
    {
        maxn = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            maxn = max(maxn, t[i][j]);
        }
        dp[j] = maxn;
    }
    int z[m + 1];
    z[0] = 0;
    maxn = INT_MIN;
    for (int i = 1; i <= m; i++)
    {
        z[i] = max(z[i - 1] + dp[i], dp[i]);
        maxn = max(maxn, z[i]);
    }
    printf("%d", maxn);
    return 0;
}