#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+5;
const int mod = 1e9+7;
int n, q, op, x, y, ans, fa[maxn];
ll a[maxn], w[maxn], fac[maxn], inv[maxn];
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
ll C(int n, int m)
{
    return 1ll * fac[n] * inv[m] % mod * inv[n-m] % mod;
}
void init()
{
    a[0] = w[0] = fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        w[i] = a[i] = 1;
        fac[i] = fac[i-1] * i % mod;
    }
    inv[n] = qpow(fac[n], mod-2);
    for (int i = n-1; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % mod;
}
void merge(int u, int v)
{
    w[v] += w[u];
    a[v] = a[v] * a[u] % mod * C(w[v]-1, w[u]) % mod;
    fa[u] = v;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    init();
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            x = (x + ans) % n, y = (y + ans) % n;
            int fx = find(x), fy = find(y);
            merge(fx, fy);
        }
        else
        {
            cin >> x;
            x = (x + ans) % n;
            int fx = find(x);
            ans = a[fx];
            cout << ans << "\n";
        }
    }
    return 0;
}