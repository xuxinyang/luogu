#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int t, n, a[N], f[N], g[N], d[N], len, cnt, ans[N], p;
int bin_less(int l, int r, int x)
{
    int ans = r;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (d[mid] > x) l = mid+1;
        else ans = mid, r = mid-1;
    }
    return ans;
}
inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    len = 1, p = 0;
    d[1] = a[1]; f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > d[len]) d[++len] = a[i], f[i] = len;
        else
        {
            int pos = lower_bound(d+1, d+len+1, a[i])-d;
            d[pos] = a[i]; f[i] = pos;
        }
    }
    len = 1;
    d[1] = a[n]; g[n] = 1;
    for (int i = n-1; i >= 1; i--)
    {
        if (a[i] < d[len]) d[++len] = a[i], g[i] = len;
        else
        {
            int pos = bin_less(1, len, a[i]);
            if (pos == 0) pos = 1;
            d[pos] = a[i]; g[i] = pos;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i]+g[i]-1 == len) ans[++p] = i;
    }
    cout << p << "\n";
    for (int i = 1; i <= p; i++) cout << ans[i] << " ";
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}