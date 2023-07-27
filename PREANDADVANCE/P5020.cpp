#include <bits/stdc++.h>
using namespace std;
const int maxm = 25005;
const int maxn = 105;
int f[maxm], a[maxn], t, n, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n;
        ans = n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (f[a[i]])
            {
                ans--;
                continue;
            }
            for (int j = a[i]; j <= a[n]; j++)
            {
                f[j] = f[j] | f[j-a[i]];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}