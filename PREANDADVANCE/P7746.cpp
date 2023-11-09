#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
const int maxm = 5e5+5;
int n, m, tot, cnt, head[maxn], w[maxn];
char op;
int fa[maxn], son[maxn], siz[maxn], dep[maxn];
int id[maxn], rev[maxn], top[maxn];
struct Edge
{
    int to, from, next;
};
Edge edges[maxn<<1];
struct SegTree
{
    int l, r, val, tag;
};
SegTree trees[maxn<<2];
void add(int u, int v)
{
    edges[++tot] = Edge{v, u, head[u]};
    head[u] = tot;
}
// 树链剖分操作
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
    rev[cnt] = w[u];
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v != fa[u] && v != son[u]) dfs2(v, v);
    }
}
// 线段树操作
void pushup(int k)
{
    trees[k].val = trees[k<<1].val + trees[k<<1|1].val;
}
void pushdown(int k, int l, int r)
{
    if (!trees[k].tag) return;
    int mid = (l + r) >> 1;
    trees[k<<1].val += trees[k].tag * (mid - l + 1);
    trees[k<<1|1].val += trees[k].tag * (r - mid);
    trees[k<<1].tag += trees[k].tag;
    trees[k<<1|1].tag += trees[k].tag;
    trees[k].tag = 0;
}
void build(int k, int l, int r)
{
    trees[k].l = l, trees[k].r = r;
    if (l == r)
    {
        trees[k].val = rev[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    pushup(k);
}
void update(int k, int l, int r, int val)
{
    if (l > r) return;
    if (trees[k].l >= l && trees[k].r <= r)
    {
        trees[k].val += val * (trees[k].r - trees[k].l + 1);
        trees[k].tag += val;
        return;
    }
    pushdown(k, trees[k].l, trees[k].r);
    int mid = (trees[k].l + trees[k].r) >> 1;
    if (l <= mid) update(k << 1, l, r, val);
    if (mid < r) update(k << 1 | 1, l, r, val);
    pushup(k);
}
int query(int k, int l, int r)
{
    if (trees[k].l >= l && trees[k].r <= r)
        return trees[k].val;
    pushdown(k, trees[k].l, trees[k].r);
    int mid = (trees[k].l + trees[k].r) >> 1;
    int ans = 0;
    if (l <= mid) ans += query(k << 1, l, r);
    if (mid < r) ans += query(k << 1 | 1, l, r);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int u, v, val;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        if (i > 1)
        {
            cin >> v;
            add(i, v);
            add(v, i);
        }
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    while (m--)
    {
        cin >> op;
        if (op == 'p')
        {
            cin >> u >> val;
            update(1, id[u]+1, id[u]+siz[u]-1, val);
        }
        else
        {
            cin >> u;
            cout << query(1, id[u], id[u]) << "\n";
        }
    }
    return 0;
}