#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lc (u << 1)
#define rc (u << 1 | 1)
constexpr int N = 1e5+5;
struct Node {
    int l, r;
    ll sum, mul, add;
} tree[N<<2];
int n, q;
ll mod, a[N];
void pushup(int u)
{
    tree[u].sum = (tree[lc].sum + tree[rc].sum) % mod;
}
// 对节点 u 的整个区间，每个数先乘 p，在加 b
void apply(int u, ll p, ll b)
{
    ll len = tree[u].r - tree[u].l + 1;
    tree[u].sum = (tree[u].sum * p + b * len) % mod;
    // 将新操作合并到已有懒标记之后
    tree[u].mul = tree[u].mul * p % mod;
    tree[u].add = (tree[u].add * p + b) % mod;
}
void pushdown(int u)
{
    if (tree[u].mul == 1 && tree[u].add == 0) return ;
    apply(lc, tree[u].mul, tree[u].add);
    apply(rc, tree[u].mul, tree[u].add);
    tree[u].mul = 1;
    tree[u].add = 0;
}
void build(int u, int l, int r)
{
    tree[u].l = l, tree[u].r = r;
    tree[u].mul = 1, tree[u].add = 0;
    if (l == r) {tree[u].sum = a[l] % mod; return; }
    int mid = (l + r) >> 1;
    build(lc, l, mid), build(rc, mid+1, r);
    pushup(u);
}
// 对区间 [l, r]，每个数先乘 p，再加 b
void update(int u, int l, int r, ll p, ll b)
{
    if (l <= tree[u].l && tree[u].r <= r)
    {
        apply(u, p, b);
        return ;
    }
    pushdown(u);
    int mid = (tree[u].l + tree[u].r) >> 1;
    if (l <= mid) update(lc, l, r, p, b);
    if (r > mid) update(rc, l, r, p, b);
    pushup(u);
}
ll query(int u, int l, int r)
{
    if (l <= tree[u].l && tree[u].r <= r)
        return tree[u].sum;
    pushdown(u);
    int mid = (tree[u].l + tree[u].r) >> 1;
    ll ans = 0;
    if (l <= mid) ans = (ans + query(lc, l, r)) % mod;
    if (r > mid) ans = (ans + query(rc, l, r)) % mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> mod;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            ll k;
            cin >> k;
            update(1, x, y, k%mod, 0);
        }
        else if (op == 2)
        {
            ll k;
            cin >> k;
            update(1, x, y, 1, k%mod);
        }
        else cout << query(1, x, y) << "\n";
    }
    return 0;
}