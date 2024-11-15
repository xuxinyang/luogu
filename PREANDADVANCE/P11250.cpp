#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
const int maxn = 2e3+5;
ll n, m, k, t;
ll c[maxn][maxn];
ll qpow(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y&1) ans = ans*x%mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans % mod;
}
void init()
{
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        if (m < k*2) cout << "0\n";
        else cout << c[n][k]%mod*c[n-k][m-k*2]%mod*qpow(2, m-k*2)%mod << "\n";
    }
    return 0;
}