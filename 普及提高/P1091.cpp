#include <bits/stdc++.h>
using namespace std;
int a[105], n, f[105], g[105], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], f[i] = 1, g[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j] && f[i] <= f[j] + 1) f[i] = f[j] + 1;
    for (int i = n-1; i >= 1; i--)
        for (int j = n; j > i; j--)
            if (a[i] > a[j] && g[i] <= g[j] + 1) g[i] = g[j] + 1;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]+g[i]-1);
    cout << n - ans << endl;
    return 0;
}