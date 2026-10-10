#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lc (u << 1)
#define rc (u << 1 | 1)
constexpr int N = 1e5+5;
struct Node {
    int l, r;
    ll sum, lazy;
} tree[N<<2];
int n, m;
ll b[N];
void pushup(int u)
{
    tree[u].sum = tree[lc].sum + tree[rc].sum;
}
// 给当前节点对应的差分区间加上 k
void apply(int u, ll k)
{
    tree[u].sum += k * (tree[u].r - tree[u].l + 1);
    tree[u].lazy += k; 
}
void pushdown(int u)
{
    if (tree[u].lazy == 0) return ;
    apply(lc, tree[u].lazy);
    apply(rc, tree[u].lazy);
    tree[u].lazy = 0;
}
void build(int u, int l, int r)
{
    tree[u].l = l, tree[u].r = r;
    tree[u].lazy = 0;
    if (l == r) 
    {
        tree[u].sum = b[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    pushup(u);
}
// 给差分数组的 [l, r] 加上 k
void update(int u, int l, int r, ll k)
{
    if (l <= tree[u].l && tree[u].r <= r) 
    {
        apply(u, k);
        return ;
    }
    pushdown(u);
    int mid = (tree[u].l + tree[u].r) / 2;
    if (l <= mid) update(lc, l, r, k);
    if (r > mid) update(rc, l, r, k);
    pushup(u);
}
// 查询差分数组的区间和
ll query(int u, int l, int r)
{
    if (l <= tree[u].l && tree[u].r <= r) return tree[u].sum;
    pushdown(u);
    int mid = (tree[u].l + tree[u].r) / 2;
    ll ans = 0;
    if (l <= mid) ans += query(lc, l, r);
    if (r > mid) ans += query(rc, l, r);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll prev = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        b[i] = x - prev;
        prev = x;
    }
    build(1, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            ll K, D;
            cin >> l >> r >> K >> D;
            update(1, l, l, K);
            if (l < r) update(1, l+1, r, D);
            if (r < n) update(1, r+1, r+1, -(K+(r-l)*D));
        }
        else
        {
            int p;
            cin >> p;
            cout << query(1, 1, p) << "\n";
        }
    }
    return 0;
}