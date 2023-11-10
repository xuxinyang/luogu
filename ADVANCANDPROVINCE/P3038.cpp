#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, tot, cnt, head[maxn], a[maxn], fa[maxn], dep[maxn];
int siz[maxn], son[maxn], top[maxn], id[maxn], rev[maxn];
struct Edge
{
    int to, next;
};
Edge edges[maxn << 1];
struct SegTree
{
    int l, r, sum, lazy;
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
        if (v == f)
            continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u, int t)
{
    top[u] = t;
    id[u] = ++cnt;
    rev[cnt] = u;
    if (!son[u])
        return;
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
        return;
    int mid = (l + r) / 2;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}
void pushdown(int k)
{
    tree[k << 1].lazy += tree[k].lazy;
    tree[k << 1 | 1].lazy += tree[k].lazy;
    tree[k << 1].sum += (tree[k << 1].r - tree[k << 1].l + 1) * tree[k].lazy;
    tree[k << 1 | 1].sum += (tree[k << 1 | 1].r - tree[k << 1 | 1].l + 1) * tree[k].lazy;
    tree[k].lazy = 0;
}
void update(int k, int l, int r)
{
    if (tree[k].r < l || tree[k].l > r)
        return;
    if (tree[k].l >= l && tree[k].r <= r)
    {
        tree[k].sum += tree[k].r - tree[k].l + 1;
        tree[k].lazy++;
        return;
    }
    pushdown(k);
    update(k << 1, l, r);
    update(k << 1 | 1, l, r);
    tree[k].sum = tree[k<<1].sum + tree[k<<1|1].sum;
}
int ask(int k, int x)
{
    if (tree[k].r < x || tree[k].l > x) return 0;
    if (tree[k].l == tree[k].r) return tree[k].sum;
    pushdown(k);
    return ask(k<<1, x) + ask(k<<1|1, x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v;
    char op;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dep[1] = 1;
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    while (m--)
    {
        cin >> op >> u >> v;
        if (op == 'P')
        {
            while (top[u] != top[v])
            {
                if (dep[top[u]] < dep[top[v]]) swap(u, v);
                update(1, id[top[u]], id[u]);
                u = fa[top[u]];
            }
            if (dep[u] > dep[v]) swap(u, v);
            update(1, id[u] + 1, id[v]);
        }
        else
        {
            if (fa[u] == v) cout << ask(1, id[u]) << "\n";
            else cout << ask(1, id[v]) << "\n";
        }
    }
    return 0;
}