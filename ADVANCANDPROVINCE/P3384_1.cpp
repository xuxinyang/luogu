#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 1e5+5;
int n, m, r, p, vistime;
int a[N], fa[N], wc[N], sz[N], top[N], dfn[N], rdfn[N], dep[N];
vector<int> e[N];
ll w[N<<4];
void dfs1(int u, int f)
{
    fa[u] = f;
    sz[u] = 1;
    dep[u] = dep[f] + 1;
    for (auto v : e[u])
    {
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[wc[u]]) wc[u] = v;   // 确定 u 的重孩子
    }
}
void dfs2(int u, int Top)
{
    dfn[u] = ++vistime;
    rdfn[vistime] = u;  // 记录 rdfn，表示 DFS 序第 vistime 个结点
    top[u] = Top;
    if (wc[u] != 0)
    {
        dfs2(wc[u], Top);   // 先递归重孩子
        for (auto v : e[u])
        {
            if (v != fa[u] && v != wc[u]) dfs2(v, v);
        }
    }
}
void pushup(int u) 
{
    w[u] = (w[u*2] + w[u*2+1]) % p;
}
void build(int u, int L, int R)
{
    if (L == R)
    {
        w[u] = a[rdfn[L]];
        return ;
    }
    int M = (L + R) / 2;
    build(u*2, L, M); build(u*2+1, M+1, R);
    pushup(u);
}
bool InRange(int L, int R, int l, int r)
{
    return (l <= L) && (R <= r);
}
bool outRange(int L, int R, int l, int r)
{
    return (L > r) || (R < l);
}
ll lzy[N<<2];
void maketag(int u, int len, ll x)
{
    lzy[u] += x;
    w[u] += len * x % p;
    lzy[u] %= p;
    w[u] %= p;
}
void pushdown(int u, int L, int R)
{
    int M = (L + R) / 2;
    maketag(u*2, M-L+1, lzy[u]);
    maketag(u*2+1, R-M, lzy[u]);
    lzy[u] = 0;
}
ll query(int u, int L, int R, int l, int r)
{
    if (InRange(L, R, l, r)) return w[u];
    else if (!outRange(L, R, l, r))
    {
        int M = (L + R) / 2;
        pushdown(u, L, R);
        return (query(u*2, L, M, l, r) + query(u*2+1, M+1, R, l, r)) % p;
    }
    else return 0;
}
void update(int u, int L, int R, int l, int r, ll x)
{
    if (InRange(L, R, l, r)) maketag(u, R-L+1, x);
    else if (!outRange(L, R, l, r))
    {
        int M = (L + R) / 2;
        pushdown(u, L, R);
        update(u*2, L, M, l, r, x);
        update(u*2+1, M+1, R, l, r, x);
        pushup(u);
    }
}
void upd(int x, int y, int z)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, 1, n, dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
    }
    update(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), z);
}
int qry(int x, int y)
{
    ll ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(1, 1, n, dfn[top[x]], dfn[x]);
        ans %= p;
        x = fa[top[x]];
    }
    return (ans + query(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]))) % p;
}
int main()
{
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    dfs1(r, 0);
    dfs2(r, 0);
    build(1, 1, n);
    for (int op, x, y, z; m; --m)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> z;
            upd(x, y, z);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            cout << qry(x, y) << "\n";
        }
        else if (op == 3)
        {
            cin >> x >> y;
            update(1, 1, n, dfn[x], dfn[x] + sz[x]-1, y);
        }
        else 
        {
            cin >> x;
            cout << query(1, 1, n, dfn[x], dfn[x]+sz[x]-1) % p << "\n";
        }
    }
    return 0;
}