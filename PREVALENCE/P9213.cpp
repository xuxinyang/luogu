#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll t, n, x, y;
ll gcd(ll x, ll y)
{
    if (x % y == 0) return y;
    else return gcd(y, x%y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        ld ans = (ld)(n-1) * gcd(x, y) / y;
        cout << (ll)ans + 1 << "\n"; 
    }
    return 0;
}