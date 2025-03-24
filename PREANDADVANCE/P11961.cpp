#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, a, p, ans;
ll qpow(ll b, ll e)
{
    if (e == 0) return 1;
    ll res = qpow(b, e / 2);
    res = res * res % p;
    if (e & 1) res = res * b % p;
    return res;
}
void check(ll x)
{
    if (qpow(a, x) == 1) ans = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> p;
        ans = 1;
        ll p1 = p - 1, p2 = p1;
        for (int i = 2; i * i <= p1; i++)
        {
            if (p1 % i == 0)
            {
                check(p1/i);
                while (p2 % i == 0) p2 /= i;
            }
        }
        if (p2 > 1) check(p1/p2);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}