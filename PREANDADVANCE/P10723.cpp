#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, root, cnt1, vis[maxn], ans;
vector<int> ve[maxn];
void add(int u, int v)
{
    ve[u].push_back(v);
}
void dfs(int u, int f)
{
    for (int v : ve[u])
    {
        if (v == f) continue;
        dfs(v, u);
        vis[u] += vis[v];
    }
}
int main()
{
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 1) vis[i] = 1, cnt1++, root = i;
    }
    int u, v;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(root, 0);
    for (int i = 1; i <= n; i++) ans += bool(vis[i]);
    cout << ans - cnt1;
    return 0;
}