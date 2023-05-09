#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;

int n, k, a[maxn];
ll ans1, ans2;
ll check(ll x)
{
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = max(sum + a[i], 0ll);
        if (sum >= x) sum = 0, ans++;
    }
    return ans;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll l = 1, r = 1e18;
    ans1 = ans2 = -1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid) <= k)
        {
            r = mid - 1;
            if (check(mid) == k) ans1 = mid;
        }
        else l = mid + 1;
    }
    l = 1, r = 1e18;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid) >= k) 
        {
            l = mid + 1;
            if (check(mid) == k) ans2 = mid;
        }
        else r = mid - 1; 
    }
    if (ans1 == -1) cout << "-1";
    else cout << ans1 << " " << ans2;
    return 0;
}