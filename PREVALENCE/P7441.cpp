#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, x, y, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> k;
        if (x > y) swap(x, y);
        if (x == 0 && y != 0)
        {
            if (k % y == 0) cout << "1\n";
            else cout << "0\n";
            continue;
        }
        if (x == 0 && y == 0)
        {
            cout << "0\n";
            continue;
        }
        ll tmp = (k - (k / x) * x) / y;
        cout << (k / y) - tmp << "\n";
    }
}