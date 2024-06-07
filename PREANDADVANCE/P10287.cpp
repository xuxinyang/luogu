#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int n, m, w[maxn], in[maxn], dp[maxn][15], ans;
vector<int> ve[maxn];
queue<int> q;
int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        ve[x].push_back(y);
        ++in[y];
    }
    for (int i = 1; i <= n; i++)
        if (!in[i]) q.push(i), dp[i][w[i]] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : ve[u])
        {
            if (--in[v] == 0) q.push(v);
            for (int i = 1; i <= w[v]; i++)
                dp[v][w[v]] = max(dp[v][w[v]], dp[u][i]+1);
            for (int i = 1; i <= 10; i++)
                dp[v][i] = max(dp[v][i], dp[u][i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 10; j++) ans = max(ans, dp[i][j]);
    }
    cout << ans;
    return 0;
}