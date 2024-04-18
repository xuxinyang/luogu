#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxq = 3e5+5;
#define mid (l+r)/2
int n, m, q, f[maxn];
int root[maxn], tot;
int ls[maxn*20], rs[maxn*20], id[maxn*20], sum[maxn*20]; 
int find(int x)
{
    return x == f[x] ? x:f[x] = find(f[x]);
}
void pushup(int u)
{
    sum[u] = sum[ls[u]] + sum[rs[u]];
}
int change(int u, int l, int r, int p, int i)   // 节点修改
{
    if (!u) u = ++tot;
    if (l == r)
    {
        id[u] = i; sum[u]++;
        return u;
    }
    if (p <= mid) ls[u] = change(ls[u], l, mid, p, i);
    else rs[u] = change(rs[u], mid+1, r, p, i);
    pushup(u);
    return u;
}
int merge(int x, int y)
{
    if (!x || !y) return x+y;
    ls[x] = merge(ls[x], ls[y]);
    rs[x] = merge(rs[x], rs[y]);
    pushup(x);
    return x;
}
int query(int u, int l, int r, int k)
{
    if (l == r) return id[u];
    int ans = 0;
    if (k <= sum[ls[u]]) ans = query(ls[u], l, mid, k);
    else ans = query(rs[u], mid+1, r, k-sum[ls[u]]);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        cin >> x;
        root[i] = change(root[i], 1, n, x, i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        x = find(x), y = find(y);
        if (x == y) continue;
        f[y] = x;
        root[x] = merge(root[x], root[y]);
    }
    cin >> q;
    while (q--)
    {
        char ch[2];
        cin >> ch;
        if (ch[0] == 'B')
        {
            cin >> x >> y;
            x = find(x), y = find(y);
            if (x == y) continue;
            f[y] = x;
            root[x] = merge(root[x], root[y]);
        }
        else
        {
            cin >> x >> y;
            x = find(x);
            int ans = query(root[x], 1, n, y);
            ans = ans ? ans:-1;
            cout << ans << "\n";
        }
    }
    return 0;
}