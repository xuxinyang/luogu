#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int maxm = 5e3+5;
const int inf = 0x3f3f3f3f;
int n, m, a[maxn], x, y;
char c;
struct Tree
{
    int l, r, mx;
};
Tree trees[maxn<<2];
// 建树
void build(int id, int l, int r)
{
    trees[id].l = l, trees[id].r = r;
    if (l == r)
    {
        trees[id].mx = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    trees[id].mx = max(trees[id<<1].mx, trees[id<<1|1].mx);
}

// 更新
void update(int id, int i, int v)
{
    if (trees[id].l == trees[id].r && trees[id].l == i)
    {
        trees[id].mx = max(trees[id].mx, v);
        return ;
    }
    int mid = (trees[id].l + trees[id].r) / 2;
    if (i <= mid) update(id << 1, i, v);
    else update(id << 1 | 1, i, v);
    trees[id].mx = max(trees[id<<1].mx, trees[id<<1|1].mx); 
}

// 查询
int query(int id, int l, int r)
{
    if (trees[id].l >= l && trees[id].r <= r)
        return trees[id].mx;
    int mid = (trees[id].l + trees[id].r) / 2;
    int Max = -inf;
    if (l <= mid)
        Max = max(Max, query(id << 1, l, r));
    if (r > mid)
        Max = max(Max, query(id << 1 | 1, l, r));
    return Max; 
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> c >> x >> y;
        if (c == 'Q') cout << query(1, x, y) << "\n";
        else update(1, x, y);
    }
    return 0;
}