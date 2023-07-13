#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, cnt, root, head[maxn], dp[maxn];
struct Edge
{
    int to, nxt, dis;
};
Edge edges[maxn << 1];
void add(int u, int v, int w)
{
    edges[++cnt] = Edge{v, head[u], w};
    head[u] = cnt;
}
void dfs(int u, int en, int fa)
{
    int sum = 0;
    for (int i = head[u]; i; i = edges[i].nxt)
    {
        if (edges[i].to != fa)
        {
            dfs(edges[i].to, i, u);
            sum += dp[edges[i].to];
        }
    }
    dp[u] = edges[en].dis;
    if (sum && sum < dp[u])
        dp[u] = sum;
}
int main()
{
    int u, v, t;
    memset(head, 0, sizeof(head));
    cin >> n >> root;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> t;
        add(u, v, t);
        add(v, u, t);
    }
    edges[0].dis = INT_MAX;
    memset(dp, 0x3f, sizeof(dp));
    dfs(root, 0, 0);
    cout << dp[root] << endl;
    return 0;
}
