#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+5;
int n, m, a[maxn], ans, d[maxn], s[maxn], t[maxn];
ll sum[maxn];
bool check(int x)
{
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= x; i++)
    {
        sum[s[i]] += d[i];
        sum[t[i]+1] -= d[i];
    }
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i-1];
    for (int i = 1; i <= n; i++)
    {
        if (sum[i] > a[i]) return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> d[i] >> s[i] >> t[i];
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    if (ans == m) cout << 0;
    else cout << -1 << "\n" << ans + 1;
    return 0;
}