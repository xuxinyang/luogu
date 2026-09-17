#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int mod = 1e9;
ll t, n;
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n <= 3)
        {
            cout << n << "\n";
            continue;
        }
        ll p = n/3, q = n%3;
        if (q == 0) cout << qpow(3, p) << "\n";
        else if (q == 1) cout << qpow(3, p-1)*4%mod<<"\n";
        else if (q == 2) cout << qpow(3, p)*2%mod << "\n";
    }
    return 0;
}