#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, f[maxn], ans, mon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int m, d;
    cin >> n;
    for (int i = 1; i <= 12; i++) mon[i] += mon[i-1];
    for (int i = 1; i <= n; i++)
    {
        cin >> m >> d;
        f[i] = mon[m-1] + d;
    }
    sort(f + 1, f + n + 1);
    f[n+1] = 367;
    for (int i = 1; i <= n + 1; i++)
    {
        ans = max(ans, f[i] - f[i-1] - 1);
    }
    ans = ans * 1.0 * 24 * 3600 / 366 + 0.5;
    cout << ans << endl;
    return 0;
}