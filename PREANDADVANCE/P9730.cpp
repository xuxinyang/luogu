#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k, p[45];
ll coord[3][3] = {
    {0, 1, 2},
    {5, 4, 3},
    {6, 7, 8},
};
ll len(ll p, ll &x, ll &y)
{
    ll px = x/p, py = y/p;
    x = x%p, y = y%p;
    if (px == 1) y = p - 1 - y;
    if (py == 1) x = p - 1 - x;
    return coord[px][py];
}
ll f(ll k, ll x, ll y)
{
    if (k == 1) return coord[x][y];
    else return p[k-1]*p[k-1]*len(p[k-1], x, y) + f(k-1, x, y);
}
int main()
{
    ll x1, y1, x2, y2;
    cin >> k;
    cin >> x1 >> y1 >> x2 >> y2;
    k = min(k, 40ll);
    p[0] = 1;
    for (int i = 1; i <= 40; i++)
        p[i] = p[i - 1] * 3;
    ll ans = f(k, x1, y1) - f(k, x2, y2);
    cout << abs(ans) << endl;
    return 0;
}