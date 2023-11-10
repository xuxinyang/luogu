#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, q, head[maxn], fa[maxn], top[maxn], siz[maxn], dep[maxn];
int cnt, tot, son[maxn], id[maxn], rev[maxn], w[maxn];
struct Edge
{
    int to, next;
};
Edge edges[maxn << 1];
struct SegTree
{
    int l, r, val, lazy;
};
SegTree tree[maxn<<2];
void add(int u, int v)
{
    edges[++tot] = Edge{v, head[u]};
    head[u] = tot;
}
void dfs1(int u, int f)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int t)
{
    top[u] = t;
    id[u] = ++cnt;
    rev[cnt] = u;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v != fa[u] && v != son[u]) 
            dfs2(v, v);
    }
}
void build(int k, int l, int r)
{
    tree[k].l = l, tree[k].r = r;
    if (l == r)
    {
        tree[k].val = w[rev[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    tree[k].val = tree[k<<1].val ^ tree[k<<1|1].val;
}
int query(int k, int l, int r)
{
    if (tree[k].l >= l && tree[k].r <= r) return tree[k].val; 
    int res = 0;
    if (tree[k<<1].r >= l) res ^= query(k<<1, l, r);
    if (tree[k<<1|1].l <= r) res ^= query(k<<1|1, l, r);
    return res;
}
void update(int k, int i, int val)
{
    if (tree[k].l == tree[k].r)
    {
        tree[k].val = val;
        return;
    }
    if (tree[k<<1].r >= i) update(k << 1, i, val);
    else update(k<<1|1, i, val);
    tree[k].val = tree[k<<1].val ^ tree[k<<1|1].val;
}
int ask(int u, int v)
{
    int ans = 0;
    while (top[u] != top[v]){
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans ^= query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans ^= query(1, id[u], id[v]);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    int op, x, y;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dep[1] = 1;
    dfs1(1, 0), dfs2(1, 1);
    build(1, 1, n);
    while (q--)
    {
        cin >> op >> x >> y;
        if (op == 1) update(1, id[x], y);
        else cout << ask(x, y) << "\n";
    }
    return 0;
}