#include <bits/stdc++.h>
using namespace std;
int n, x, y, c, ans;
int main()
{
    cin >> n >> x >> y;
    c = min(min(n-x+1, x), min(n-y+1, y));  // circles;
    ans = 4 * (n - c + 1) * (c - 1);
    if (x == c) ans += y - c + 1;
    else if (y == n - c + 1) ans += n - 3 * c + x + 2;
    else if (x == n - c + 1) ans += 3 * n - 5 * c - y + 4;
    else ans += 4 * n - 7 * c - x + 5;
    cout << ans << endl;
    return 0;
}