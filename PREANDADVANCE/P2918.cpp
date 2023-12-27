#include <bits/stdc++.h>
using namespace std;
const int maxh = 5e4+5e3;
const int maxn = 105;
const int inf = 1e9;
int n, m, a[maxn], b[maxn], f[maxh];
int ans = 1e9;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m + 5000; i++) f[i] = inf;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= m + 5000; j++)
        {
            f[j] = min(f[j], f[j-a[i]] + b[i]);
        }
    }
    for (int i = m; i <= m + 5000; i++)
        ans = min(ans, f[i]);
    cout << ans;
    return 0;
}