#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 105;
const int MAXM = 2005;
const int MOD = 998244353;
int n, m;
ll cnt[MAXN], w[MAXN][MAXM], dp[MAXN][MAXM], ans;
int main()
{
    scanf("%d%d", &n, &m);
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%lld", &w[i][j]), cnt[i] = (cnt[i] + w[i][j]) % MOD;
        ans = (ans * (cnt[i] + 1)) % MOD;
    }
    ans = (ans + MOD - 1) % MOD;
    for (int i = 1; i <= m; i++)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++)
            for (int k = 0; k <= (j-1)<<1; k++)
            {
                dp[j][k] = (dp[j][k] + dp[j-1][k] * (cnt[j]-w[j][i]) % MOD) % MOD;
                dp[j][k+1] = (dp[j][k+1] + dp[j-1][k]) % MOD;
                dp[j][k+2] = (dp[j][k+2] + dp[j-1][k] * w[j][i] % MOD) % MOD;
            }   
        for (int j = n+1; j <= n<<1; j++)
            ans = (ans + MOD - dp[n][j]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}