#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], b[maxn], m, n, p, q, ans, k;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (m >= n)
    {
        cout << 0 << endl; 
        return 0;
    } 
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);
    p = q = 1;
    for (int i = 1; i <= m; i++)
    {
        while (b[p] <= a[i] && p <= n) p++;
        if (b[p] > a[i]) b[p] = 0, k++;
    }
    if (k < m)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            ans += b[i];
        cout << ans << endl;
    }
    return 0;
}