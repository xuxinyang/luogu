#include <bits/stdc++.h>
using namespace std;
int n, k, a[1005], sum[1005], ans;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i];
    int l = 1, r = 2;
    while (r <= n)
    {
        if (a[r]-a[l] <= k) ans = max(ans, sum[r]-sum[l-1]), r++;
        else l++;
    }
    cout << ans;
    return 0;
}