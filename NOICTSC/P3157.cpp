#include <bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define ls tr[u].l
#define rs tr[u].r
#define lowbit(x) (x&-x)
const int maxn = 1e5+5;
int n, m, a[maxn], pos[maxn], rt[maxn], tot;
struct Node
{
    int s, l, r;
};
Node tr[maxn*300];
long long ans;
void change(int &u, int l, int r, int v, int k)
{
    if (!u) u = ++tot;
    tr[u].s += k;
    if (l == r) return;
    if (v <= mid) change(ls, l, mid, v, k);
    else change(rs, mid+1, r, v, k);
}
void change(int x, int v, int k)
{
    while (x <= n) change(rt[x], 1, n, v, k), x += lowbit(x);
}
int qmore(int u, int l, int r, int v)
{
    if (!u) return 0;
    if (v < l) return tr[u].s;
    int ret = 0;
    ret += qmore(rs, mid+1, r, v);
    if (v <= mid) ret += qmore(ls, l, mid, v);
    return ret;
}
int qmore(int x, int v)
{
    int ret = 0;
    while (x) ret += qmore(rt[x], 1, n, v), x -= lowbit(x);
    return ret;
}
int qless(int u, int l, int r, int v)
{
    if (!u) return 0;
    if (v > r) return tr[u].s;
    int ret = 0;
    ret += qless(ls, l, mid, v);
    if (v > mid) ret += qless(rs, mid+1, r, v);
    return ret;
}
int qless(int x, int v)
{
    int ret = 0;
    while (x) ret += qless(rt[x], 1, n, v), x -= lowbit(x);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
        ans += qmore(i-1, a[i]);
        change(i, a[i], 1);
    }
    while (m--)
    {
        cout << ans << "\n";
        cin >> v;
        ans -= qmore(pos[v]-1, v) + qless(n, v) - qless(pos[v]-1, v);
        change(pos[v], v, -1);
    }
    return 0;
}