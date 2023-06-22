#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}
int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}
int main()
{
    int x0, y0, p, q, ans = 0;
    cin >> x0 >> y0;
    for (int i = x0; i <= y0; i += x0)
    {
        int p = x0 * y0 / i;
        if (gcd(i, p) == x0 && lcm(i, p) == y0)
            ans ++;
    }
    cout << ans;
    return 0;
}