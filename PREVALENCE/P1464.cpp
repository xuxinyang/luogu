#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mem[25][25][25];
ll w(ll, ll, ll);
ll W(ll x, ll y, ll z)
{
    if (mem[x][y][z]) return mem[x][y][z];
    else return mem[x][y][z] = w(x, y, z);
}
ll w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return W(20, 20, 20);
    if (a < b && b < c)
        return W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
    return W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
            return 0;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
    return 0;
}