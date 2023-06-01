#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, x, z;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> x >> z;
        if (z % x != 0)
        {
            cout << -1 << "\n";
            continue;
        }
        ll tmp = __gcd(z/x, x*x);
        ll p = (ll)(sqrt(tmp) + 0.5);
        if (p * p != tmp) cout << -1 << "\n";
        else cout << (z/x)/p << "\n";
    }
    return 0;
}