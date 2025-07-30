#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, a, b;
bool check(ll mid)
{
    ll xa = mid*a, xb = mid*b;
    if (xa > n)
    {
        ll y = (xa-n+a-b-1)/(a-b);
        xa -= y*(a-b);
        xb += y*(a-b);
    }
    return xa<=n&&xb<=m;
}
int main()
{
    cin >> n >> m >> a >> b;
    if (n < m) swap(n, m);
    if (a < b) swap(a, b);
    ll l = 0, r = n, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
    cout << ans;
    return 0;
}