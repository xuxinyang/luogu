#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n, m, p, t, x, a[maxn], ans;
int main()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        while (t--)
        {
            cin >> x;
            a[x]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (a[i] == p) ans++;
    }
    cout << ans << endl;
    for (int i = 1; i <= m; i++)
    {
        if (a[i] == p) cout << i << " ";
    }
    return 0;
}