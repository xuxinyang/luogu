#include <bits/stdc++.h>
using namespace std;
int n, p, q;
int gcd(int x, int y)
{
    return __gcd(x, y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> q;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1 || b == 1) cout << p << "\n";
        else if (a == b) cout << 0 << "\n";
        else if (gcd(a, b) == 1) cout << min(p, 2*q) << "\n";
        else cout << min(q, 2*p) << "\n";
    }
    return 0;
}