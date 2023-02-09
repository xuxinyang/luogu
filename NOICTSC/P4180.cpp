#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+5;
const ll inf = 1e15+5;
struct Edge
{
    int u, v, w;
    bool operator < (const Edge &e)
    {
        return w < e.w;
    }
}edges[maxn];
vector<pair<int, int> > v[maxn];
int n, m, fa[maxn], vis[maxn], dep[maxn], f[maxn][20], mx[maxn][20], me[maxn][20];
ll sum;
int find(int x)
{
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fx] = fy;
}
void kruskal()
{
    sort(edges + 1, edges + m + 1);
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            merge(edges[i].u, edges[i].v);
            tot++;
            sum += edges[i].w;
            vis[i] = 1;
            v[edges[i].u].push_back(make_pair(edges[i].v, edges[i].w));
            v[edges[i].v].push_back(make_pair(edges[i].u, edges[i].w));
        }
        if (tot == n - 1) break;
    }
}
void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1, f[x][0] = fa;
    for (int i = 0; i < v[x].size(); i++)
    {
        int to = v[x][i].first;
        if (to == fa) continue;
        mx[to][0] = v[x][i].second;
        dfs(to, x);
    }
}
void multipre()
{
    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[j][i] = f[f[j][i-1]][i-1];
            int topf = f[j][i-1];
            mx[j][i] = max(mx[j][i-1], mx[topf][i-1]);
            me[j][i] = max(me[j][i-1], me[topf][i-1]);
            if (mx[j][i-1] > mx[topf][i-1])
                me[j][i] = max(me[j][i], mx[topf][i-1]);
            else if (mx[j][i-1] < mx[topf][i-1])
                me[j][i] = max(me[j][i], mx[j][i-1]);
        }
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 18; i >= 0; i--)
        if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    if (x == y) return x;
    for (int i = 18; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
int findMax(int x, int lca, int val)
{
    ll ans = 0;
    for (int i = 18; i >= 0; i--)
    {
        if (dep[f[x][i]] >= dep[lca])
        {
            if (mx[x][i] == val) ans = max(ans, (ll)me[x][i]);
            else ans = max(ans, (ll)mx[x][i]);
            x = f[x][i];
        }
    }
    return ans;
}
void solve()
{
    ll ans = inf;
    for (int i = 1; i <= m; i++)
    {
        if (vis[i]) continue;
        int x = edges[i].u, y = edges[i].v, z = edges[i].w;
        int lcav = lca(x, y);
        int lmx = findMax(x, lcav, z), rmx = findMax(y, lcav, z);
        if (max(lmx, rmx) != z) ans = min(ans, sum + z - max(lmx, rmx));
    }
    cout << ans << endl;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    kruskal();
    dfs(1, 0);
    multipre();
    solve();
    return 0;
}