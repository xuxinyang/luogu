#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll m, n;
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    cin >> m >> n;
    if (n < m) 
    {
        cout << 0;
        return 0;
    }
    ll a = 1, b = 1;
    for (ll i = 1; i <= m-1; i++)
    {
        a = a * (n-i) % mod;
        b = b * i % mod;
    }
    ll ans = a * qpow(b, mod-2) % mod;
    cout << ans;
    return 0;
}