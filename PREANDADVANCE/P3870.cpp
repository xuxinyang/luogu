#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e5 + 5;
int n, m, c, a, b;
struct Node
{
    int l, r, v, sum_off, sum_on, status;
} tree[maxn << 2];
// 建树
void build(int k, int l, int r)
{
    tree[k].l = l, tree[k].r = r;
    if (l == r)
    {
        tree[k].sum_off++;
        return;
    }
    int mid = (l + r) / 2;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    tree[k].sum_off = tree[k << 1].sum_off + tree[k << 1 | 1].sum_off;
}
void tag(int k)
{
    if (tree[k].status == 0)
        return;
    swap(tree[k << 1].sum_off, tree[k << 1].sum_on);
    swap(tree[k << 1 | 1].sum_off, tree[k << 1 | 1].sum_on);
    tree[k << 1].status ^= 1;
    tree[k << 1 | 1].status ^= 1;
    tree[k].status = 0;
}
void update(int k, int l, int r)
{
    if (tree[k].l >= l && tree[k].r <= r)
    {
        tree[k].status ^= 1;
        swap(tree[k].sum_off, tree[k].sum_on);
        return;
    }
    tag(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if (l <= mid)
        update(k << 1, l, r);
    if (mid < r)
        update(k << 1 | 1, l, r);
    tree[k].sum_off = tree[k << 1].sum_off + tree[k << 1 | 1].sum_off;
    tree[k].sum_on = tree[k << 1].sum_on + tree[k << 1 | 1].sum_on;
}
int query(int k, int l, int r)
{
    if (tree[k].l >= l && tree[k].r <= r)
        return tree[k].sum_on;
    tag(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    int sum = 0;
    if (l <= mid)
        sum += query(k << 1, l, r);
    if (mid < r)
        sum += query(k << 1 | 1, l, r);
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> c >> a >> b;
        if (c == 0)
        {
            update(1, a, b);
        }
        else
        {
            cout << query(1, a, b) << "\n";
        }
    }
    return 0;
}