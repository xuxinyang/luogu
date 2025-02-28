#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, a[N], f[N], g[N], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) f[i] = min(f[i-1]+1, a[i]);
    for (int i = n; i >= 1; i--) g[i] = min(g[i+1]+1, a[i]);
    for (int i = 1; i <= n; i++)
        ans = max(ans, min(f[i], g[i]));
    cout << ans;
    return 0;
}