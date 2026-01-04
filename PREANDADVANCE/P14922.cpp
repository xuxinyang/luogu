#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n, c[N], a[N], ans, f[N][N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(c+1, c+n+1);
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = i; k <= n; k++)
            {
                int d = 0;
                if (i > 1) d = c[n-j+1]-c[j];
                f[j][k] = max(f[j][k], f[j-1][k-i]+a[i]+d);
                if (k == n) ans = max(ans, f[j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}