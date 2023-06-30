#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m[25][25][25];
ll w(ll x, ll y, ll z)
{
    if (x <= 0 || y <= 0 || z <= 0)
        return 1;
    if (x > 20 || y > 20 || z > 20)
        return w(20, 20, 20);
    if (m[x][y][z]) return m[x][y][z];
    if (x < y && y < z)
        return m[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
    return m[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
}
int main()
{
    ll a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
            return 0;
        else
            cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
    return 0;
}