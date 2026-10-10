#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lc (u << 1)
#define rc (u << 1 | 1)
constexpr int N = 5e5+5;
struct Node {
    int l, r;
    ll sum, lmax, rmax, ans;
}tree[N<<2];
int n, m;
ll a[N];

// 合并两个相邻区间, L 必须在 R 左边
Node mergeNode(const Node& L, Node& R)
{
    Node res; 
    res.l = L.l, res.r = R.r;
    res.sum = L.sum + R.sum;
    res.lmax = max(L.lmax, L.sum + R.lmax);
    res.rmax = max(R.rmax, R.sum + L.rmax);
    res.ans = max({L.ans, R.ans, L.rmax+R.lmax});
    return res;
}

void pushup(int u)
{
    tree[u] = mergeNode(tree[lc], tree[rc]);
}
void build(int u, int l, int r)
{
    tree[u].l = l, tree[u].r = r;
    if (l == r) 
    {
        tree[u].sum = tree[u].lmax = tree[u].rmax = tree[u].ans = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    pushup(u);
}
void update(int u, int p, ll value)
{
    if (tree[u].l == tree[u].r)
    {
        tree[u].sum = tree[u].lmax = tree[u].rmax = tree[u].ans = value;
        return ;
    }
    int mid = (tree[u].l + tree[u].r) >> 1;
    if (p <= mid) update(lc, p, value);
    else update(rc, p, value);
    pushup(u);
}
Node query(int u, int l, int r)
{
    if (l <= tree[u].l && tree[u].r <= r) return tree[u];
    int mid = (tree[u].l + tree[u].r) >> 1;
    if (r <= mid) return query(lc, l, r);
    if (l > mid) return query(rc, l, r);
    Node L = query(lc, l, r);
    Node R = query(rc, l, r);
    return mergeNode(L, R);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            cout << query(1, x, y).ans << "\n";
        }
        else 
        {
            int p;
            ll s;
            cin >> p >> s;
            update(1, p, s);
        }
    }
    return 0;
}