#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, b, c, d, e, ans = 0;
    cin >> r >> b >> c >> d >> e;
    if (r > b)
        ans = max(r * c + b * d, b * 2 * e + (r - b) * c);
    else if (r < b)
        ans = max(r * c + b * d, r * 2 * e + (b - r) * d);
    else
        ans = max(r * c + b * d, 2 * r * e);
    cout << ans;
    return 0;
}