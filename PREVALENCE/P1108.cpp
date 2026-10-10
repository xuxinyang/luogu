#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e3+5;
int n, a[N], f[N], cnt[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int maxLen = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        cnt[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] > a[i])
            {
                if (f[j]+1 > f[i]) f[i] = f[j]+1, cnt[i] = cnt[j];
                else if (f[j]+1 == f[i]) cnt[i] += cnt[j];
            }
            else if (a[j] == a[i]) cnt[j] = 0;
        }
        maxLen = max(maxLen, f[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == maxLen) ans += cnt[i];
    }
    cout << maxLen << " " << ans;
    return 0;
}