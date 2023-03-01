#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, c, a[1005], ans;
int main()
{
    cin >> n >> m >> k;
    memset(a, 0x3f, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> c;
        a[x] = min(a[x], c);
    }
    for (int i = 1; i <= m; i++)
    {
        ans += a[i] <= 1e6+5 ? a[i] : 0;
    }
    cout << min(ans, k);
    return 0;
}