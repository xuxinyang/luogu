#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
const int maxm = 2e5+5;
const int mod = 1e9+7;
int n, m, in[maxn], out[maxn], to[maxn], fa[maxn];
bool flag;
ll ans, k;
ll fac(ll n)
{
    ll res = 1;
    for (ll i = 1; i <= n; i++) res = res * i % mod;
    return res;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    if (fx != fy) fa[fx] = fy;
    return 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    if (m == 0)
    {
        cout << fac(n) << endl;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (!to[u])
        {
            to[u] = v;
            in[v]++; out[u]++;
            if (!merge(u, v)) flag = 1;
        }
        else if (to[u] != v) flag = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] > 1 || out[i] > 1) {flag = 1; continue;}
        if (in[i] == 0) k++;
    }
    if (flag) cout << 0;
    else cout << fac(k);
    return 0;
}