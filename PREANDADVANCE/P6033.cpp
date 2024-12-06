#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxm = 1e5+5;;
ll n, x, ans, a[maxm], maxx;
queue<ll> p, q;
ll read()
{
    ll x = 0; char c = getchar(); bool flag = 0;
    while (c > '9' || c < '0')
    {
        if (c == '-') flag = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x*10+c-'0', c = getchar();
    return (flag?-x:x);
}
ll getTop()
{
    ll res;
    if (q.empty() || (!p.empty()&&p.front()<q.front()))
        res = p.front(), p.pop();
    else res = q.front(), q.pop();
    return res;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        x = read();
        a[x]++;
        maxx = max(maxx, x);
    }
    for (int i = 1; i <= maxx; i++)
    {
        for (int j = 1; j <= a[i]; j++) p.push(i);
    }
    for (int i = 1; i < n; i++)
    {
        ll a = getTop(), b = getTop();
        ans += a+b;
        q.push(a+b);
    }
    cout << ans;
    return 0;
}