#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5 + 5;
const int mod = 998244353;
ll n, m, head[maxn], tot, dep[maxn];
struct Edge
{
    ll to, next;
};
Edge edges[maxn << 1];
ll fa[maxn][25], pre[maxn][55];
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void add(ll u, ll v)
{
    edges[++tot] = Edge{v, head[u]};
    head[u] = tot;
}
void dfs(ll u, ll f)
{
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 50; i++)
        pre[u][i] = (pre[f][i] + qpow(dep[u], i) + mod) % mod;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == f) continue;
        dfs(v, u);
    }
}
ll lca(ll x, ll y)
{
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[x] <= dep[y] - (1 << i))
            y = fa[y][i];
    if (x == y) return x;
    for (int i = 20; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll u, v, z;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dep[1] = -1;
    dfs(1, 1);
    for (int j = 1; j <= 21; j++)
    {
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
    cin >> m;
    while (m--)
    {
        cin >> u >> v >> z;
        int t = lca(u, v);
        int sum1 = (pre[u][z] + pre[v][z] + mod) % mod;
        int sum2 = (pre[t][z] + pre[fa[t][0]][z] + mod) % mod;
        cout << (sum1 - sum2 + mod) % mod << "\n";
    }
    return 0;
}