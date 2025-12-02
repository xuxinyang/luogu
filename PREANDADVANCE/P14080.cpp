#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll n, m, fa[N], dep[N], nw[N], flag[N], res, f[N], re[N], ans[N];
struct Node
{
    ll u, v, w, id;
}nodes[N];
vector<Node> g;
vector<pair<int, int>> ve[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void dfs(int x, int fa)
{
    f[x] = fa;
    dep[x] = dep[fa] + 1;
    for (auto e : ve[x])
    {
        if (e.first == fa) continue;
        re[e.second] = e.first;
        dfs(e.first, x);
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        nw[i] = w;
        nodes[i] = {u, v, w, i};
    }
    sort(nodes+1, nodes+m+1, [&](Node A, Node B){
        return A.w < B.w;
    });
    for (int i = 1; i <= m; i++)
    {
        int x = find(nodes[i].u), y = find(nodes[i].v);
        if (x == y)
        {
            g.push_back(nodes[i]);
            continue;
        }
        flag[nodes[i].id] = 1; // 最小生成树上的边
        ve[nodes[i].u].push_back({nodes[i].v, nodes[i].id});
        ve[nodes[i].v].push_back({nodes[i].u, nodes[i].id});
        res += nodes[i].w;
        fa[x] = y;
    }
    for (int i = 2; i <= n; i++)
    {
        if (find(i) != find(1))
        {
            for (int j = 1; j <= m; j++) cout << -1 << "\n";
            return 0;
        }
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) ans[i] = -1, fa[i] = i;
    for (auto e : g)
    {
        int u = find(e.u), v = find(e.v), w = e.w;
        while (u != v)
        {
            if (dep[u] < dep[v]) swap(u, v);
            ans[u] = w;
            fa[u] = find(f[u]);
            u = find(u);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (flag[i])
        {
            if (ans[re[i]] == -1) cout << "-1\n";
            else cout << res-nw[i]+ans[re[i]] << "\n";
        }
        else cout << res << "\n";
    }
    return 0;
}