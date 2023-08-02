#include <bits/stdc++.h>
using namespace std;
const int maxn = 25005;
int n, x, y, m, b;
int a[maxn], c[maxn], ans;
int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    sort(a + 1, a + n + 1);
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > c[i]) ans += y * (a[i] - c[i]);
        else ans += x * (c[i] - a[i]);
    }
    cout << ans;
    return 0;
}