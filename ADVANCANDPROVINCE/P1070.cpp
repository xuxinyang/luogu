#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, m, p;
int f[maxn][maxn], cost[maxn], q[maxn][maxn], pos[maxn][maxn];
int l[maxn], r[maxn], sum[maxn], dp[maxn];
int get(int i, int j) {return ((j-i)%n+n)%n;}
int main()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> f[j][i];
            f[j][i] += f[j-1][i-1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
        q[i][++r[i]] = -cost[i], l[i]++;
    }
    memset(dp, 0xcf, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int idx = get(i, j);
            while (l[idx] <= r[idx] && pos[idx][l[idx]]+p < i) l[idx]++;
            if (!j) sum[idx] += f[i][n];
            if (l[idx] <= r[idx]) dp[i] = max(dp[i], q[idx][l[idx]]+sum[idx]+f[i][j]);
        }
        for (int j = 0; j < n; j++)
        {
            int idx = get(i, j);
            int tmp = dp[i] - sum[idx] - f[i][j] - cost[j];
            while (l[idx] <= r[idx] && q[idx][r[idx]] <= tmp) r[idx]--;
            pos[idx][++r[idx]] = i;
            q[idx][r[idx]] = tmp;
        }
    }
    cout << dp[m];
    return 0;
}