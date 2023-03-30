#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
bitset<maxn> a, b;
int l, n, x, y, z, ans1, ans2;
int main()
{
    cin >> l >> n;
    a.set(), b.set();
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        if (x == 0)
        {
            for (int j = y; j <= z; j++)
            {
                ans2 += a[j] ^ b[j];
                a.reset(j), b.reset(j);
            }
        }
        if (x == 1)
        {
            for (int j = y; j <= z; j++) a.set(j);
        }
    }
    for (int i = 0; i <= l; i++)
        ans1 += a[i] ^ b[i];
    cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}