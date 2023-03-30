#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
struct Tree
{
    int left, right;
    int mx;
    int lazy;
};
Tree trees[maxn << 2];
struct Building
{
    int l, r, h;
    bool operator < (const Building A) const
    {
        return h < A.h;
    }
};
Building builds[maxn];
int a[maxn];

// 建树
void build(int id, int l, int r)
{
    trees[id].left = l;
    trees[id].right = r;
    trees[id].lazy = 0;
    if (trees[id].left == trees[id].right)
    {
        trees[id].mx = 0;
        return ;
    }
    int mid, lc, rc;
    mid = (l + r) / 2, lc = id * 2, rc = id * 2 + 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

// 懒操作
void push(int id)
{
    if (trees[id].lazy)
    {
        trees[id*2].lazy = trees[id].lazy;
        trees[id*2+1].lazy = trees[id].lazy;
        trees[id*2].mx = max(trees[id*2].mx, trees[id*2].lazy);
        trees[id*2+1].mx = max(trees[id*2+1].mx, trees[id*2+1].lazy);
        trees[id].lazy = 0;
    }
}

// 更新
void update(int id, int l, int r, int v)
{
    if (trees[id].left == l && trees[id].right == r)
    {
        trees[id].mx = max(trees[id].mx, v);
        trees[id].lazy = v;
        return ;
    }
    push(id);
    int lc = id * 2;
    int rc = id * 2 + 1;
    if (r <= trees[lc].right) update(lc, l, r, v);
    else if (l >= trees[rc].left) update(rc, l, r, v);
    else
    {
        update(lc, l, trees[lc].right, v);
        update(rc, trees[rc].left, r, v);
    }
    trees[id].mx = max(trees[lc].mx, trees[rc].mx);
}
// 查询
int query(int id, int l, int r)
{
    if (trees[id].left == l && trees[id].right == r)
        return trees[id].mx;
    push(id);
    int lc = id * 2, rc = id * 2 + 1;
    if (r <= trees[lc].right) return query(lc, l, r);
    else if (l >= trees[rc].left) return query(rc, l, r);
    else return max(query(lc, l, trees[lc].right), query(rc, trees[rc].left, r));
}
int main()
{
    build(1, 1, 10000);
    int l, h, r;
    int cnt = 1;
    while (cin >> builds[cnt].l >> builds[cnt].h >> builds[cnt].r)
    {
        if (builds[cnt].l + builds[cnt].h + builds[cnt].r == 0)
            break;
        cnt++;
    }
    sort(builds + 1, builds + cnt);
    for (int i = 1; i < cnt; i++)
    {
        update(1, builds[i].l, builds[i].r - 1, builds[i].h);
    }
    for (int i = 1; i <= 10000; i++)
    {
        a[i] = query(1, i, i);
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (a[i] != a[i-1])
            cout << i << " " << a[i] << " ";
    }
    return 0;
}