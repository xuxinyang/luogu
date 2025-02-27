#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dep = 1, st[15], ans[15], flag;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
void dfs(ll a, ll b, int x)
{
    if (x == dep-1)
    {
        ll mink = ceil(sqrt(4*b/(a*a)));
        for (ll k = mink; ; k++)
        {
            ll delta = k*k*a*a-4*b*k;
            ll t = sqrt(delta), gd = -1;
            if (t*t == delta) gd = t;
            else if ((t+1)*(t+1) == delta) gd = t+1;
            else if ((t-1)*(t-1) == delta) gd = t-1;
            ll x = (k*a-gd)/2, y = (k*a+gd)/2;
            if (y > 1e7 || flag&&y>=ans[dep]) break;
            if (gd <= 0 || (a*k-gd)%2!=0) continue;
            st[dep-1] = x, st[dep] = y;
            memcpy(ans, st, sizeof(st));
            flag = 1;
            break;
        }
        return;
    }
    if (x > dep) return;
    if (a == 1 && b > st[x-1])
    {
        st[x] = b;
        if (!flag || st[x] < ans[x])
        {
            for (int i = 1; i <= dep; i++) ans[i] = st[i];
        } 
        flag = 1;
        return; 
    }
    ll l = max(b/a+1, st[x-1]+1);
    ll r = (dep-x+1)*b/a;
    if (flag && r >= ans[dep]) r = ans[dep]-1;
    for (ll i = l; i < r; i++)
    {
        st[x] = i;
        ll t = a*i-b;
        ll d = b*i;
        ll g = gcd(t, d);
        dfs(t/g, d/g, x+1);
    }    
}
int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll g = gcd(a, b);
    a /= g, b /= g; st[0] = 1;
    for (dep = 1; dep <= 10; dep++)
    {
        dfs(a, b, 1);
        if (flag)
        {
            for (int i = 1; i <= dep; i++) printf("%lld ", ans[i]);
            return 0;
        }
    }
    return 0;
}