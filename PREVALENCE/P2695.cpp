#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
const int maxm = 2e4+5;
int n, m, a[maxn], b[maxm], ans, cnt;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int p = 1, q = 1;
    while (p <= n && q <= m)
    {
        if (a[p] <= b[q])
        {
            ans += b[q];
            p++, q++;
            cnt++;
        }
        else q++;
    }
    if (cnt < n) cout << "you died!\n";
    else cout << ans;
    return 0;
}