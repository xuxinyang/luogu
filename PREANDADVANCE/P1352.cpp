#include <bits/stdc++.h>
using namespace std;
vector<int> edges[6005];
int n, u, v, p[6005], dp[6005][2], fa[6005];
void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = p[u];
    for (int i = 0; i < edges[u].size(); i++)
    {
        int v = edges[u][i];
        dfs(v);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n-1; i++)
    {
        cin >> v >> u;
        edges[u].push_back(v);
        fa[v] = u;
    }
    int root = 1;
    while (fa[root] != 0) root = fa[root];
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}