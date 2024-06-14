#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> ve[maxn];
int n, m, u, v, maxx, minx;
bool vis[maxn], color[maxn];
void dfs(int cur)
{
    vis[cur] = 1;
    if (color[cur]) v++;
    else u++;
    for (auto e: ve[cur])
    {
        if (vis[e]) continue;
        color[e] = color[cur]^1;
        dfs(e);
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        u = 0, v = 0;
        dfs(i);
        color[i] = 1;
        maxx += max(u, v);
        minx += min(u, v);
    }
    cout << minx << " " << maxx;
    return 0;
}