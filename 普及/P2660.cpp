#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x, y, ans;
int main()
{
    cin >> x >> y;
    while (x && y)
    {
        swap(x, y);
        ans += 4 * y * (x / y);
        x %= y;
    }
    cout << ans << "\n";
    return 0;
}