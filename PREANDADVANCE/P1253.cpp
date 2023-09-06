#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6 + 5;
const ll inf = LLONG_MAX;
ll n, q, op, l, r, x, a[maxn];
struct Trie
{
    ll mx, lzc, lzs;
};
Trie tree[maxn << 2];
void cover(ll k)
{
    if (tree[k].lzc != -inf)
    {
        tree[k<<1].lzs = tree[(k<<1)|1].lzs = 0;
        tree[k<<1].mx = tree[(k<<1)|1].mx = tree[k].lzc;
        tree[k<<1].lzc = tree[(k<<1)|1].lzc = tree[k].lzc;
        tree[k].lzc = -inf;
    }
}
void sum(ll k)
{
    if (tree[k].lzs)
    {
        cover(k);
        tree[k<<1].mx += tree[k].lzs, tree[(k<<1)|1].mx += tree[k].lzs;
        tree[k<<1].lzs += tree[k].lzs, tree[(k<<1)|1].lzs += tree[k].lzs;
        tree[k].lzs = 0;
    }
}
void pushdown(ll k)
{
    cover(k);
    sum(k);
}
void build(ll k, ll l, ll r)
{
    if (l == r)
    {
        tree[k].mx = a[l];
        tree[k].lzc = -inf;
        tree[k].lzs = 0;
        return;
    }
    ll mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    tree[k].mx = max(tree[k * 2].mx, tree[k * 2 + 1].mx);
}
void updateSum(ll k, ll l, ll r, ll kl, ll kr, ll v)
{
    if (kl <= l && kr >= r)
    {
        cover(k);
        tree[k].mx += v;
        tree[k].lzs += v;
        return;
    }
    pushdown(k);
    ll mid = (l + r) >> 1;
    if (kl <= mid) updateSum(k<<1, l, mid, kl, kr, v);
    if (kr > mid) updateSum((k<<1)|1, mid+1, r, kl, kr, v);
    tree[k].mx = max(tree[k * 2].mx, tree[k * 2 + 1].mx);
}
void updateCover(ll k, ll l, ll r, int kl, int kr, ll v)
{
    if (kl <= l && kr >= r)
    {
        tree[k].lzs = 0;
        tree[k].mx = v;
        tree[k].lzc = v;
        return;
    }
    pushdown(k);
    ll mid = (l + r) >> 1;
    if (kl <= mid) updateCover(k<<1, l, mid, kl, kr, v);
    if (kr > mid) updateCover((k<<1)|1, mid+1, r, kl, kr, v);
    tree[k].mx = max(tree[k * 2].mx, tree[k * 2 + 1].mx);
}
ll query(ll k, ll l, ll r, ll kl, ll kr)
{
    ll res = -inf;
    if (kl <= l && kr >= r) return tree[k].mx;
    pushdown(k);
    ll mid = (l + r) / 2;
    if (kl <= mid) res = max(res, query(k*2, l, mid, kl, kr));
    if (kr > mid) res = max(res, query(2*k+1, mid+1, r, kl, kr));
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= n << 2; i++) tree[i].lzc = -inf;
    for (int i = 1; i <= q; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> x;
            updateCover(1, 1, n, l, r, x);
        }
        else if (op == 2)
        {
            cin >> l >> r >> x;
            updateSum(1, 1, n, l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }

    }
    return 0;
}