#include <bits/stdc++.h>
using namespace std;
const int N = 65;
int q, x, y;
int a[N], b[N], cnta, cntb;
int f[N], t;
void fac(int x, int a[])
{
    a[0] = x;
    t = 0;
    for (int i = 2; i*i <= x; i++)
    {
        while (x % i == 0) f[++t] = i, x/=i;
    }
    if (x > 1) f[++t] = x;
    for (int i = 1; i <= t; i++)
        a[i] = a[i-1] / f[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        fac(x, a), fac(y, b);
        int px = 0, py = 0;
        while (a[px] != b[py])
        {
            if (a[px] > b[py]) px++;
            else py++;
        }
        cout << px + py << "\n";
    }
    return 0;
}