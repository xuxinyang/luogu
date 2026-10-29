#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+5;
constexpr int inf = 1e9;
struct Seg {
    int v, ls, rs;
} t[N<<8];
int rt[N<<2], cnt, n, m;
void pushup(int o)
{
    t[o].v = t[t[o].ls].v + t[t[o].rs].v;
}
void change(int lsto, int &o, int l, int r, int q, int v)
{
    if (!o) o = ++cnt;
    if (l == r) {t[o].v += v; return; }
    int mid = (l + r) >> 1;
    if (q <= mid)
    {
        t[o].rs = t[lsto].rs;
        t[o].ls = ++cnt;
        t[t[o].ls] = t[t[lsto].ls];
        change(t[lsto].ls, t[o].ls, l, mid, q, v);
    }
    else
    {
        t[o].ls = t[lsto].ls;
        t[o].rs = ++cnt;
        t[t[o].rs] = t[t[lsto].rs];
        change(t[lsto].rs, t[o].rs, mid+1, r, q, v);
    }
    pushup(o);
}
int query(int o1, int o2, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) return t[o2].v - t[o1].v;
    int mid = (l + r) >> 1, res = 0;
    if (ql <= mid) res += query(t[o1].ls, t[o2].ls, l, mid, ql, qr);
    if (qr > mid) res += query(t[o1].rs, t[o2].rs, mid+1, r, ql, qr);
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        change(rt[i-1], rt[i], 1, inf, tmp, tmp);
    }
    cin >> m;
    while (m--)
    {
        int ans = 1, l, r, lst = 0;
        cin >> l >> r;
        while (1)
        {
            int res = query(rt[l-1], rt[r], 1, inf, lst+1, ans);
            lst = ans;
            if (res) ans = res + ans;
            else break;
        }
        cout << ans << "\n";
    }
    return 0;
}