#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        if (n == 2)
            cout << x << "\n";
        else if (x % 2 == 1)
        {
            cout << x * (ll)pow(2, n - 2) << "\n";
        }
        else
        {
            ll k = x, t = n;
            while (k % 2 == 0 && t > 2)
            {
                t--;
                k /= 2;
            }
            cout << k * (ll)pow(2, n - 2) << "\n";
        }
    }
    return 0;
}