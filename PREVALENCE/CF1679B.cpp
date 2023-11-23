#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
const int inf = INT_MAX;
int n, q, t, x, k, a[maxn];
struct SegTree
{
    int l, r;
    ll sum, lazy;
};
SegTree trees[maxn<<2];
void pushdown(int k)
{
    if (trees[k].lazy)
    {
        trees[k<<1].lazy = trees[k].lazy;
        trees[k<<1].sum = trees[k].lazy * (trees[k<<1].r - trees[k<<1].l + 1);
        trees[k<<1|1].lazy = trees[k].lazy;
        trees[k<<1|1].sum = trees[k].lazy * (trees[k<<1|1].r - trees[k<<1|1].l + 1);
        trees[k].lazy = 0;
    }
}
void build(int k, int l, int r)
{
    trees[k].l = l;
    trees[k].r = r;
    if (l == r)
    {
        trees[k].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1, l, mid);
    build(k<<1|1, mid+1, r);
    trees[k].sum = trees[k<<1].sum + trees[k<<1|1].sum;
}
void update(int k, int l, int r, ll v)
{
    if (trees[k].l == l && trees[k].r == r)
    {
        trees[k].sum = v * (trees[k].r - trees[k].l + 1);
        trees[k].lazy = v;   
        return ;
    }
    pushdown(k);
    int mid = (trees[k].l + trees[k].r) >> 1;
    if (r <= mid) update(k<<1, l, r, v);
    else if  (l > mid) update(k<<1|1, l, r, v);
    else update(k<<1, l, mid, v), update(k<<1|1, mid+1, r, v);
    trees[k].sum = trees[k<<1].sum + trees[k<<1|1].sum;
}
ll query(int k, int l, int r)
{
    if (trees[k].l == l && trees[k].r == r)
        return trees[k].sum;
    pushdown(k);
    int mid = (trees[k].l + trees[k].r) >> 1;
    if (r <= mid) return query(k<<1, l, r);
    else if (l > mid) return query(k<<1|1, l, r);
    else return query(k<<1, l, mid) + query(k<<1|1, mid+1, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> k >> x;
            update(1, k, k, x);
        }
        else
        {
            cin >> x;
            update(1, 1, n, x);
        }
        cout << query(1, 1, n) << "\n";
    }
    return 0;
}