#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 55;
const int maxv = 2e6+5;
ll n, m, a[maxn], f[maxv], g[maxv], ans;
int p, q;
void dfs(int l, int r, ll d[], ll sum, int &idx)
{
    if (sum > m) return;
    if (l > r) {d[++idx] = sum; return;}
    dfs(l+1, r, d, sum+a[l], idx);
    dfs(l+1, r, d, sum, idx);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mid = (1 + n) >> 1;
    dfs(1, mid, f, 0, p);
    dfs(mid+1, n, g, 0, q);
    sort(g+1, g+q+1);
    for (int i = 1; i <= p; i++)
    {
        ans += upper_bound(g+1, g+q+1, m-f[i])-g-1;
    }
    cout << ans;
    return 0;
}