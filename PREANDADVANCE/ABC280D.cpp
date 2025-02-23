#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
#define ll long long
ll k, n;
ll gcd(ll x, ll y)
{
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}
int main()
{
    cin >> k;
    ll p = sqrt(k);
    for (int i = 2; i <= 2*p; i++)
    {
        k /= gcd(k, i);
        if (k == 1)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << k;
    return 0;
}