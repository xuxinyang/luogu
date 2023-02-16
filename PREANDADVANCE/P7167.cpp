#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e16;
const int maxn=1e5+5;
ll n, q, d[maxn], c[maxn], l[maxn], head[maxn], tot;
stack<ll> s;
struct Edge
{
    ll next, to;
}edges[maxn];
inline void add(ll x, ll y)
{
    edges[++tot].to = y;
    edges[tot].next = head[x];
    head[x] = tot;
}
ll f[maxn][17], g[maxn][17], dep[maxn];
inline void dfs(ll u, ll fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa, g[u][0] = c[fa];
    for (ll i = 1; (1 << i) <= dep[u]; i++)
        f[u][i] = f[f[u][i-1]][i-1], g[u][i] = g[f[u][i-1]][i-1] + g[u][i-1];
    for (ll i = head[u]; i; i = edges[i].next) {
        ll v = edges[i].to;
        dfs(v, u);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> d[i] >> c[i];
    d[n+1] = inf, c[n+1] = inf;
    s.push(1);
    for (ll i = 2; i <= n + 1; i++)
    {
        while (!s.empty() && d[i] > d[s.top()])
        {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (ll i = 1; i <= n; i++) add(l[i], i);
    dfs(n+1, 0);
    for (ll i = 1; i <= q; i++) 
    {
        ll r, v;
        cin >> r >> v;
        if (c[r] >= v)
        {
            cout << r << "\n";
            continue;
        }
        v -= c[r];
        ll x = r, ans = 0;
        for (ll i = 16; i >= 0; i--)
        {
            if (g[x][i] <= v && (1 << i) <= dep[x]) 
            {
                v -= g[x][i]; x = f[x][i];
            }
            if (v == 0) ans = x;
        }
        if (ans == 0) ans = f[x][0];
        if (ans == n + 1) cout << 0 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}