#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, k, a[maxn], f[maxn], ans;
bool cmp(const int &a, const int &b)
{
    return a <= b;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        f[i] = lower_bound(a+1, a+n+1, a[i]+k,cmp) - a-i;
    for (int i = n; i >= 1; i--)
        ans = max(ans, f[i]+f[i+f[i]]), f[i] = max(f[i], f[i+1]);
    cout << ans << endl;
    return 0;
}