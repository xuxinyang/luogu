#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e8;
ll n, m;
struct MAT
{
    ll a[3][3], r, c;
};
MAT mul(MAT x, MAT y)
{

    MAT res;
    memset(&res, 0, sizeof(res));
    for (int i = 0; i < x.r; i++)
        for (int j = 0; j < y.c; j++)
            for (int k = 0; k < x.c; k++)
                res.a[i][j] = (res.a[i][j]+x.a[i][k]*y.a[k][j]) % mod;
    res.r = x.r, res.c = y.c;
    return res;
}
void mqpow(ll k)
{
    MAT res, ans;
    memset(&res, 0, sizeof(res));
    memset(&ans, 0, sizeof(ans));
    res.r = res.c = 2;
    res.a[0][0] = res.a[0][1] = res.a[1][0] = 1;
    ans.r = 1, ans.c = 2;
    ans.a[0][0] = ans.a[0][1] = 1;
    while (k)
    {
        if (k & 1) ans = mul(ans, res);
        res = mul(res, res);
        k >>= 1;
    }
    cout << ans.a[0][0];
}
ll gcd(ll x, ll y)
{
    if (x % y == 0) return y;
    return gcd(y, x%y);
}
int main()
{
    cin >> n >> m;
    n = gcd(n, m);
    if (n <= 2) cout << 1;
    else mqpow(n-2);
    return 0;
}