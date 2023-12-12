#include <bits/stdc++.h>
using namespace std;
#define ls u << 1
#define rs u << 1 | 1
const int maxn = 1e5+5;
struct Line
{
    int x1, x2, y;
    int tag;    // 入边(+1), 出边(-1)
    bool operator < (Line &t)
    {
        return y < t.y;
    }
};
Line lines[maxn<<1];
struct SegTree
{
    int l, r;
    int cnt, len;   // 分别代表区间覆盖次数和区间覆盖长度
};
SegTree trees[maxn<<4];
int n, x[maxn<<1];
long long ans;
void build(int u, int l, int r)
{
    trees[u] = {l, r, 0, 0};
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);                                                                                                               
}
void pushup(int u)
{
    int l = trees[u].l, r = trees[u].r;
    if (trees[u].cnt) trees[u].len = x[r+1] - x[l];
    else trees[u].len = trees[ls].len + trees[rs].len;
}
void modify(int u, int l, int r, int tag)
{
    if (l > trees[u].r || r < trees[u].l) return;
    if (l <= trees[u].l && r >= trees[u].r)
    {
        trees[u].cnt += tag;
        pushup(u);
        return;
    }
    modify(ls, l, r, tag);
    modify(rs, l, r, tag);
    pushup(u);
}
int main()
{
    int x1, x2, y1, y2;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        lines[i] = {x1, x2, y1, 1};
        lines[n+i] = {x1, x2, y2, -1};
        x[i] = x1, x[n+i] = x2;
    }
    n <<= 1;
    sort(lines + 1, lines + n + 1); // 扫描线排序
    sort(x + 1, x + n + 1); // x坐标排序
    int s = unique(x + 1, x + n + 1) - x - 1;   // 去重
    build(1, 1, s-1);   // 构建线段树
    for (int i = 1; i < n; i++)
    {
        int l = lower_bound(x+1, x+s+1, lines[i].x1) - x;
        int r = lower_bound(x+1, x+s+1, lines[i].x2) - x;
        modify(1, l, r-1, lines[i].tag);
        ans += 1ll*trees[1].len * (lines[i+1].y - lines[i].y);
    }
    cout << ans;
    return 0;
}