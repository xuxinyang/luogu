#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, l , r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        ll tmp = (r - l + 1) % 9;
        ll ans = tmp * (l % 9) % 9 + tmp * (tmp - 1) % 9 * 5 % 9;
        cout << ans % 9 << "\n";
    }
    return 0;
}