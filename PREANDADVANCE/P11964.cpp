#include <bits/stdc++.h>
using namespace std;
int n, m, k, dp[25][505][505], tot, head[505];
// dp[i][j][k] 表示
struct Edge
{
    int to, next;
};
Edge edges[1005];
void add(int u, int v)
{
    edges[++tot] = (Edge){v, head[u]};
    head[u] = tot;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++) dp[0][i][i] = 1;   // 自己到自己可达
    for (int t = 1; t <= k; t++)    // 枚举走k步
    {
        for (int i = 1; i <= n; i++)    // 枚举起点
        {
            for (int j = 1; j <= n; j++)    // 枚举可能到达的点
            {
                if (dp[t-1][i][j])  // 如果走t-1步可以到达i到j
                // 从j点枚举下一个可以到达的点
                for (int k = head[j]; k; k = edges[k].next)
                {
                    int v = edges[k].to;
                    dp[t][i][v] = 1;
                }
            }
        }
    }
    // 统计答案并输出
    for (int i = 1; i <= n; i++)
    {
        for (int t = 1; t <= k; t++)
        {
            int ans = 0;
            for (int j = 1; j <= n; j++)
            {
                ans += dp[t][i][j];
            }
            printf("%d%c", ans, " \n"[t==k]);
        }
    }
    return 0;
}