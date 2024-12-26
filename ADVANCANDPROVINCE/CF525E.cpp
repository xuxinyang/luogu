#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const int maxn = 30;
int n, k, a[maxn], mid;
int sts[maxn];
ll s, ans;
map<pll, int> mp;
map<ll, bool> vis;
ll fac(ll x)
{
    ll res = 1;
    for (int i = x; i >= 1; i--)
    {
        if (res > s/i) return -1;
        res *= i;
    }
    return res;
}
void check()
{
    ll sum = 0, cnt = 0;
    for (int i = 1; i <= mid; i++)
    {
        if (sts[i] == 1) 
        {
            if (sum + a[i] > s) return;
            sum += a[i];
        }
        else if (sts[i] == 2)
        {
            ll t = fac(a[i]);
            if (t == -1 || cnt+1 > k || sum+t>s) return;
            sum += t; cnt++;
        }
    }
    mp[make_pair(cnt, sum)]++; vis[sum] = 1;
}
void dfs(int x)
{
    if (x > mid) {check(); return;}
    for (int i = 0; i <= 2; i++)
    {
        sts[x] = i;
        dfs(x+1);
    }
}
ll calc(ll cnt, ll sum)
{
    ll t = 0;
    for (int i = 0; i <= cnt; i++) t += mp[make_pair(i, sum)];
    return t;
}
void check2()
{
    ll sum = 0, cnt = 0;
    for (int i = mid+1; i <= n; i++)
    {
        if (sts[i] == 1) 
        {
            if (sum + a[i] > s) return;
            sum += a[i];
        }
        else if (sts[i] == 2)
        {
            ll t = fac(a[i]);
            if (t == -1 || cnt+1 > k || sum+t>s) return;
            sum += t; cnt++;
        }
    }
    if (vis.count(s-sum)) ans += calc(k-cnt, s-sum);
}
void dfs2(int x)
{
    if (x > n) {check2(); return;}
    for (int i = 0; i <= 2; i++)
    {
        sts[x] = i;
        dfs2(x+1);
    }
}
int main()
{
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    mid = n/2;
    dfs(1); dfs2(mid+1);
    cout << ans;
    return 0;
}