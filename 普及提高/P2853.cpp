#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
bool vis[MAXN];
int in[MAXN], f[MAXN];
int k, n, m, ans, u, v;
vector<int> edges[MAXN];

void dfs(int x)
{
    vis[x] = 1, f[x]++;
    for (int i = 0; i < edges[x].size(); i++)
    {
        if (!vis[edges[x][i]]) dfs(edges[x][i]);
    }
}

int main()
{
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++) cin >> in[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
    }
    for (int i = 1; i <= k; i++) 
    {
        for (int j = 1; j <= n; j++) vis[j] = 0;
        dfs(in[i]);
    }
    for (int i = 1; i <= n; i++)
        if (f[i] == k) ans++;
    cout << ans << endl;
    return 0;
}