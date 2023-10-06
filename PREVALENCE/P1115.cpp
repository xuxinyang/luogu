#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, a[maxn], f[maxn], ans = INT_MIN;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = max(f[i-1] + a[i], a[i]);
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}