#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n, a[N], k, ans;
bool check(int x)
{
    int cnt = 1, s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s + a[i] <= x) s += a[i];
        else cnt++, s = a[i];
    }
    return cnt <= k;
}
int main()
{
    cin >> n;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], l = max(l, a[i]), r += a[i];
    cin >> k;
    // cout << l << " " << r << "\n";
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid-1;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}