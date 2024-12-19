#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<ll, bool> ump;
ll n, k, x, cnt;
void solve(ll n, ll k)
{
    for (ll i = 2; i * i * i <= n; i++)
    {
        ll t = i * i, m = 2;
        while (t <= n/i)
        {
            t *= i;
            m++;
            if (m < k) continue;
            if (ump[t]) continue;
            if ((ll)sqrtl(t)*sqrtl(t) == t) x++;
            ump[t] = 1, cnt++;
        }
    }
}
int main()
{
    cin >> n >> k;
    solve(n, k);
    if (k == 1) cout << n;
    else if (k >= 3) cout << cnt+1;
    else cout << (ll)sqrtl(n)+cnt-x;
    return 0;
}