#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[25][25][25];
ll w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (f[a][b][c]) return f[a][b][c];
    if (a < b && b < c)
        return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1) return 0;
        else 
            cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << "\n" ;
    }
    return 0;
}