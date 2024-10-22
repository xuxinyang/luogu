#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxl = 90 * 105;
int L, s, t, m, stone[maxn], a[maxn], dp[maxl], base;
bool vis[maxl];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L;
    cin >> s >> t >> m;
    base = s * t;
    for (int i = 1; i <= m; i++) cin >> stone[i];
    sort(stone+1, stone+m+1);
    if (s == t)
    {
        int cnt = 0;
        for (int i = 1; i <= m; i++)
            if (stone[i] % s == 0) cnt++;
        cout << cnt << endl;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int d = stone[i] - stone[i-1];
        if (d >= base) d = base;
        a[i] = a[i-1] + d;
        vis[a[i]] = 1;
    }
    L = a[m] + base;
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= L; ++i)
    {
        for (int j = s; j <= t; j++)
        {
            if (i - j >= 0)
            {
                if (vis[i]) dp[i] = min(dp[i-j]+1, dp[i]);
                else dp[i] = min(dp[i-j], dp[i]);
            }
        }
    }
    int ans= maxn;
    for (int i = a[m]; i <= L; i++) ans = min(ans, dp[i]);
    cout << ans;
    return 0;
}