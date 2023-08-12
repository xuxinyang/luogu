#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll a, b, c, d, e, f;
ll gcd(ll x, ll y)
{
    return __gcd(x, y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        d = a + b + c;
        e = min(min(a, b), c);
        f = max(max(a, b), c);
        b = d - e - f;
        a = e, c = f;
        // cout << a << " " << b << " " << c << "\n";
        if (a == 0 && b == 0) cout << "0\n";
        else if (a == 0)
        {
            if (b == c) cout << "1\n";
            else cout << "2\n";
        }
        else
        {
            if (a + b == c) cout << "2\n";
            else if (a == b || b == c) cout << "2\n";
            else cout << "3\n";
        }
    }
    return 0;
}