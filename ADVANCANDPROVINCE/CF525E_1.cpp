#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 105;
int n, t, m, b[N];
ll S, ans, a[N];
map<pair<int, ll>, int > mp;
ll fact(ll x)
{
    ll ret;
    for (ret = 1; x; ret *= x--)
        if (S/ret < x) return -1;
    return ret;
}
void check1()
{
    ll cnt = 0;
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if (b[i] == 1) sum += a[i];
        else if (b[i] == 2)
        {
            ll s = fact(a[i]);
            if (s==-1 || (++cnt > t) || (s+sum) > S) return;
            sum += s;
        }
    }
    mp[{cnt, sum}]++;
    mp[{-1, sum}]++;
}
void dfs1(int u)
{
    if (u > m) check1();
    else 
    {
        for (int i = 0; i <= 2; i++)
        {
            b[u] = i;
            dfs1(u+1);
        }
    }
}
map<pair<int, ll>, ll > g;
ll query(int x, ll s)
{
    if (g.count({x, s})) return g[{x, s}];
    return g[{x, s}] = mp[{x, s}] + (x ? query(x-1, s):0);
}
void check2()
{
    int cnt = 0;
    ll sum = 0;
    for (int i = m+1; i <= n; i++)
    {
        if (b[i] == 1) sum += a[i];
        else if (b[i] == 2)
        {
            ll s = fact(a[i]);
            if (s==-1 || ++cnt>t || (s+sum)>S) return;
            sum += s;
        }
    }
    if (mp.count({-1, S-sum})) ans += query(t-cnt, S-sum);
}
void dfs2(int u)
{
    if (u > n) check2();
    else 
    {
        for (int i = 0; i <= 2; i++)
        {
            b[u] = i;
            dfs2(u + 1);
        }
    }
}
int main()
{
    cin >> n >> t >> S;
    for (int i = 1; i <= n; i++) cin >> a[i];
    m = n >> 1;
    dfs1(1);
    dfs2(m+1);
    cout << ans;
    return 0;
}