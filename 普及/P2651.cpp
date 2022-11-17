#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll x, ll y)
{
    return __gcd(x, y);
}
ll t, n, x, x2, res = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> x >> x2;
        res = x;
        for (int i = 3; i <= n; i++)
        {
            cin >> x;
            res = gcd(res, x2) * gcd(x, x2); 
        }
        if (res % x2 == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}