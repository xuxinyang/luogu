#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0) return x;
    else return gcd(y, x % y);
}
int main()
{
    ios::sync_with_stdio(false);
    int t, x1, y1, x2, y2;
    cin >> t;
    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (gcd(abs(x1-x2), abs(y1-y2)) == 1) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}