#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+5;
int n, m, e, q, fa[N<<2], a[N<<2], sz[N<<2], st[N<<2], vis[N<<2], sum;
pair<int, int> g[N<<2];
int ans[N<<2];
int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (!st[fx] && st[fy])
    {
        st[fx] = 1;
        sum += sz[fx];
    }
    else if (st[fx] && !st[fy])
    {
        st[fy] = 1;
        sum += sz[fy];
    }
    if (fx == fy) return;
    fa[fx] = fy;
    sz[fy] += sz[fx];
}
int main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[i] = {u, v};
    }
    for (int i = 1; i <= n; i++) sz[i] = 1;
    for (int i = 1; i <= n+m; i++) fa[i] = i;
    for (int i = n+1; i <= n+m; i++) st[i] = 1;

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    for (int i = 1; i <= e; i++)
    {
        if (!vis[i]) merge(g[i].first, g[i].second);
    }
    for (int i = q; i >= 1; i--)
    {
        ans[i] = sum;
        merge(g[a[i]].first, g[a[i]].second);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}