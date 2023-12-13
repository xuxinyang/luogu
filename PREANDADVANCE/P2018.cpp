#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
const int inf = INT_MAX;
int n, cnt, dp[N][N], head[N], ans;
struct Edge
{
    int to, next;
};
Edge edges[N<<1];
void add(int u, int v)
{
    edges[++cnt] = Edge{v, head[u]};
    head[u] = cnt;
}
int dfs(int u, int f)
{
    if (dp[u][f]) return dp[u][f];
    int idx = 0, a[N];
    for (int i = head[u]; i; i = edges[i].next)
    {
        if (edges[i].to == f) continue;
        a[++idx] = dfs(edges[i].to, u);
    }
    if (idx)
    {
        sort(a + 1, a + idx + 1);
        for (int i = 1; i <= idx; i++)
            dp[u][f] = max(dp[u][f], a[i] + idx - i + 1);
    }
    else dp[u][f] = 1;
    return dp[u][f];
}
int main()
{
    cin >> n;
    int u;
    for (int i = 2; i <= n; i++)
    {
        cin >> u;
        add(u, i), add(i, u);
    }
    ans = inf;
    for (int i = 1; i <= n; i++) ans = min(ans, dfs(i, 0));
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (dp[i][0] == ans) cout << i << " ";
    return 0;
}