#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+5;
int n, m, a[N<<1], cnt[N<<1];
int f[N<<1][20];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    int len = 2 * n, inf = len + 2;
    int r = 0, kind = 0;
    for (int l = 1; l <= len; l++)
    {
        while (r < len && kind < m)
        {
            r++;
            if (cnt[a[r]] == 0) kind++;
            cnt[a[r]]++;
        }
        if (kind == m) f[l][0] = r + 1;
        else f[l][0] = inf;
        cnt[a[l]]--;
        if (cnt[a[l]] == 0) kind--;
    }
    f[len+1][0] = f[inf][0] = inf;
    for (int k = 1; k < 20; k++)
    {
        for (int i = 1; i <= inf; i++)
            f[i][k] = f[f[i][k-1]][k-1];
    }
    int ans = 0;
    for (int s = 1; s <= n; s++)
    {
        int pos = s;
        int sum = 0;
        int limit = s + n;
        for (int k = 19; k >= 0; k--)
        {
            if (f[pos][k] <= limit)
            {
                pos = f[pos][k];
                sum += (1<<k);
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}