#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, q, w[maxn], head[maxn], tot, cnt, fa[maxn], son[maxn], siz[maxn], dep[maxn];
int id[maxn], rev[maxn], top[maxn];
struct Edge
{
    int to, next;
};
Edge edges[maxn << 1];
struct SegTree
{
    int l, r, val, lazy;
};
SegTree tree[maxn << 2];
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
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] < siz[son[u]])
            son[u] = v;
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
    int mid = (l + r) / 2;
    build(k<<1, l, mid);
    build(k<<1|1, mid+1, r);
    tree[k].val = tree[k<<1].val + tree[k<<1|1].val;
}
void update(int k, int i, int val)
{
    if (i == tree[k].l && i == tree[k].r)
    {
        tree[k].val = val;
        return;
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    if (i <= mid) update(k<<1, i, val);
    else update(k<<1|1, i, val);
    tree[k].val = tree[k<<1].val + tree[k<<1|1].val; 
}
int query(int k, int l, int r)
{
    int ans = 0;
    if (l == tree[k].l && r == tree[k].r) return tree[k].val;
    int mid = (tree[k].l + tree[k].r) / 2;
    if (l <= mid) ans += query(k<<1, l, r);
    if (r > mid) ans += query(k<<1|1, l, r);
    return ans;
}
int check(int l, int r)
{
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int tmp = query(1, mid + 1, r);
    if (tmp) return check(mid + 1, r);
    else return check(l, mid);
}
int ask(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        int tmp = query(1, id[top[u]], id[u]);
        if (!tmp) u = fa[top[u]];
        else return check(id[top[u]], id[u]);
    }
    if (dep[u] > dep[v]) swap(u, v);
    return check(id[u], id[v]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char op;
    int u, v;
    cin >> n >> q;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dep[1] = 1;
    dfs1(1, 0), dfs2(1, 1);
    build(1, 1, n);
    while (q--)
    {
        cin >> op >> v;
        if (op == 'C') update(1, id[v], 1);
        else cout << rev[ask(1, v)] << "\n";
    }
    return 0;
}