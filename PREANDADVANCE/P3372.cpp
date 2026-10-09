#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lc (u << 1)
#define rc (u << 1 | 1)
constexpr int N = 100000 + 5;
struct Node
{
    int l, r;
    ll sum, lazy;
} tree[N << 2];

int n, m;
ll a[N];
// 用左右子节点的区间和更新父节点
void pushup(int u)
{
    tree[u].sum = tree[lc].sum + tree[rc].sum;
}
// 给节点 u 对应的整个区间加上 k
void add(int u, ll k)
{
    tree[u].sum += k * (tree[u].r - tree[u].l + 1);
    tree[u].lazy += k;
}
// 将尚未传给子节点的加法下传
void pushdown(int u)
{
    if (tree[u].lazy == 0) return;
    add(lc, tree[u].lazy);
    add(rc, tree[u].lazy);
    tree[u].lazy = 0;
}

void build(int u, int l, int r)
{
    tree[u].l = l;
    tree[u].r = r;
    tree[u].lazy = 0;
    if (l == r)
    {
        tree[u].sum = a[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(lc, l, m);
    build(rc, m + 1, r);
    pushup(u);
}
// 将区间 [l, r] 内的每个数加上 k
void update(int u, int l, int r, ll k)
{
    // 当前节点区间被完整覆盖
    if (l <= tree[u].l && tree[u].r <= r)
    {
        add(u, k);
        return;
    }
    // 访问子节点前，先下传已有的懒标记
    pushdown(u);
    int m = tree[u].l + (tree[u].r - tree[u].l) / 2;
    if (l <= m) update(lc, l, r, k);
    if (r > m) update(rc, l, r, k);
    // 子节点修改后，重新计算当前节点的区间和
    pushup(u);
}

// 查询区间 [l, r] 的和
ll query(int u, int l, int r)
{
    if (l <= tree[u].l && tree[u].r <= r) return tree[u].sum;
    pushdown(u);
    int m = tree[u].l + (tree[u].r - tree[u].l) / 2;
    ll s = 0;
    if (l <= m) s += query(lc, l, r);
    if (r > m) s += query(rc, l, r);
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            ll k;
            cin >> k;
            update(1, x, y, k);
        }
        else cout << query(1, x, y) << '\n';
    }
    return 0;
}