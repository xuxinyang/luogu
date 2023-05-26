#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3+5;
const int maxm = 1e7+5;
int n, m, head[maxn], tot;
int fee[maxn], dp[maxn][maxn];
struct Edge
{
    int to, next, w;
};
Edge edges[maxm];
void add(int u, int v, int w)
{
    edges[++tot] = (Edge){v, head[u], w};
    head[u] = tot;
}
int dfs(int u)
{
    if (u > n - m)
    {
        dp[u][1] = fee[u];
        return 1;
    }
    int sum = 0, t;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        t = dfs(v);
        sum += t;
        for (int j = sum; j > 0; j--)
        {
            for (int k = 1; k <= t; k++)
            {
                if (j - k >= 0)
                    dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[v][k] - edges[i].w);
            }
        }
    }
    return sum;
}
int main()
{
    memset(dp, 0xc0, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n - m; i++)
    {
        int t, v, w;
        cin >> t;
        while (t--)
        {
            cin >> v >> w;
            add(i, v, w);
        }
    }
    for (int i = n - m + 1; i <= n; i++) cin >> fee[i];
    for (int i = 1; i <= n; i++) dp[i][0] = 0;
    dfs(1);
    for (int i = m; i >= 1; i--)
    {
        if (dp[1][i] >= 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}