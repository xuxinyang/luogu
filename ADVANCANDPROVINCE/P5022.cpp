#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
vector<int> e[maxn];
pair<int, int> edge[maxn];
int du, dv, vis[maxn];
vector<int> path(maxn, maxn);
int n, m, cnt, better;
bool dfs(int u)
{
    if (!better)
    {
        if (u > path[cnt]) return true; // 没有必要继续走了
        if (u < path[cnt]) better = -1; // 继续往后走
    }
    vis[u] = 1;
    path[cnt++] = u;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (vis[v]) continue;
        if (v == du && u == dv || v == dv && u == du) continue;
        if (dfs(v)) return true;
    }
    return false;
}
int main()
{
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        edge[i] = {u, v};
    }
    for (int i = 1; i <= n; i++) sort(e[i].begin(), e[i].end());
    if (n == m + 1) dfs(1);
    else
    {
        for (int i = 1; i <= m; i++)
        {
            du = edge[i].first, dv = edge[i].second;
            memset(vis, 0, sizeof(vis));
            cnt = better = 0;
            dfs(1);
        }
    }
    for (int i = 0; i < n; i++) cout << path[i] << " ";
    return 0;
}