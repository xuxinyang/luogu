#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, c, m, op, k, ans, mina, minb, minc;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> m;
    ans = a * b * c;
    while (m--)
    {
        cin >> op >> k;
        if (op == 1)
        {
            if (k <= mina) k = 0;
            else k = k-mina, mina = k;
            ans -= k * b * c;
        }
        else if (op == 2)
        {
            if (k <= minb) k = 0;
            else k = k-minb, minb = k;
            ans -= k * a * c;
        }
        else
        {
            if (k <= minc) k = 0;
            else k = k-minc, minc = k;
            ans -= k * a * b;
        }
        if (ans < 0) ans = 0;
        cout << ans << "\n";
    }
    return 0;
}