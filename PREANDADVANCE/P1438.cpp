#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, a[maxn], opt;
struct Node
{
    int l, r, sum, add;
};
Node tree[maxn<<2];

void build(int k, int l, int r)
{
    tree[k].l = l, tree[k].r = r;
    if (l == r)
    {
        tree[k].sum = tree[k].add = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(k<<1, l, mid);
    build(k<<1|1, mid+1, r);
    tree[k].add = 0;
    tree[k].sum = tree[k<<1].sum + tree[k<<1|1].sum;
}
void update(int k, int l, int r, int v)
{
    if (tree[k].l >= l && tree[k].r <= r)
    {
        tree[k].add += v;
        tree[k].sum = tree[k].add * (r - l + 1);
        if (l != r)
        {
            tree[k].sum += tree[k<<1].sum + tree[k<<1|1].sum;
        } 
        return;
    }
    int mid = (tree[k].l + tree[k].r) / 2;
    if (l <= mid) update(k<<1, l, r, v);
    if (r > mid) update(k<<1|1, l, r, v);
    tree[k].sum = tree[k].add * (r - l + 1);
    if (l != r)
    {
        tree[k].sum += tree[k<<1].sum + tree[k<<1|1].sum;
    } 
}
int query(int k, int l, int r, int v)
{
    int res = 0;
    if (tree[k].l >= l && tree[k].r <= r)
    {
        res += tree[k].sum + v * (r-l+1);
        return res;
    }
    int mid = (tree[k].l + tree[k].r) / 2;
    if (l <= mid) 
        res += query(k<<1, l, r, v + tree[k].add);
    if (r > mid)
        res += query(k<<1|1, l, r, v + tree[k].add);
    return res;
}   
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, r, k, d, p;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n-1; i >= 1; i--) a[i+1] = a[i+1]-a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> l >> r >> k >> d;
            update(1, l, l, k);
            if (l != r) update(1, l+1, r, d);
            if (r != n) update(1, r+1, r+1, -k-d*(r-l));
        }
        else
        {
            cin >> p;
            cout << query(1, 1, p, 0) << "\n";
        }
    }
    return 0;
}