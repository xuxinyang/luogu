#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int n, m, r, p, w[maxn], op;
int head[maxn], tot, cnt, fa[maxn], dep[maxn];
int siz[maxn], son[maxn], top[maxn], Max, Sum;
int id[maxn], rev[maxn];
struct Edge
{
    int to, next;
};
Edge edges[maxn<<1];
struct Node
{
    int l, r, mx, sum;
};
Node tree[maxn<<2];
int read()  // 快读
{
    char c;
    int sign = 1;
    while ((c=getchar()) < '0' || c > '9')
        if (c == '-') sign = -1;
    int res = 0;
    while ((c == getchar()) >= '0' && c <= '9')
        res = res * 10 + c - '0';
    return res;
}
void add(int u, int v)  // 加边
{
    edges[++cnt] = Edge{v, head[u]};
    head[u] = cnt;
}
void dfs1(int u, int f) // 求dep, fa, siz, son
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
void dfs2(int u, int t) // 求top, id, rev
{
    top[u] = t;
    id[u] = ++tot;
    rev[tot] = u;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v != fa[u] && v != son[u]) dfs2(v, v);
    }
}
void build(int k, int l, int r) // 构建线段树
{
    tree[k].l = l, tree[k].r = r;
    if (l == r)
    {
        tree[k].mx = tree[k].sum = w[rev[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(k<<1, l, mid);
    build((k<<1)+1, mid+1, r);
    tree[k].mx = max(tree[k<<1].mx, tree[(k<<1)+1].mx);
    tree[k].sum = tree[k<<1].sum + tree[(k<<1)+1].sum;
}
void query(int k, int l, int r) // 查询最值，和
{
    if (tree[k].l >= l && tree[k].r <= r)
    {
        Max = max(Max, tree[k].mx);
        Sum += tree[k].sum;
        return ;
    }
    int mid = (tree[k].l + tree[k].r) / 2;
    if (l <= mid) query(k<<1, l, r);
    if (r > mid) query((k<<1)+1, l, r);
}
void ask(int u, int v)  // 求u，v区间最值或者和
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    query(1, id[u], id[v]);
}   
void update(int k, int i, int val)  // 修改
{
    if (tree[k].l == tree[k].r && tree[k].l == i)
    {
        tree[k].mx = tree[k].sum = val;
        return;
    }
    int mid = (tree[k].l + tree[k].r) / 2;
    if (i <= mid) update(k<<1, i, val);
    else update((k<<1)+1, i, val);
    tree[k].mx = max(tree[k<<1].mx, tree[(k<<1)+1].mx);
    tree[k].sum = tree[k<<1].sum + tree[(k<<1)+1].sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    n = read(), m = read(), r = read(), p = read();
    for (int i = 1; i <= n; i++) w[i] = read();
    int x, y, z;
    for (int i = 1; i <= n-1; i++)
    {
        x = read(), y = read();
        add(x, y);
        add(y, x);
    }
    dep[1] = 1;
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, tot);
    for (int i = 1; i <= m; i++)
    {
        op = read();
        switch (op)
        {
        case 1:
            x = read(), y = read(), z = read();
            break;
        case 2:
            x = read(), y = read();
            break;
        case 3:
            x = read(), z = read();
            break;
        case 4:
            x = read();
            break;
        default:
            break;
        }
    }
    return 0;
}