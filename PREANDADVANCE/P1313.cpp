#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
const int mod = 1e4+7;
ll f[maxn][maxn], ans;
ll qpow(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}
int main()
{
    ll a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
            if (j == 0 || j == i) f[i][j] = 1;
            else f[i][j] = (f[i-1][j]+f[i-1][j-1]) % mod;
    }
    ans = f[k][n] * qpow(a, n) % mod * qpow(b, m) % mod;
    cout << ans;
    return 0;
}