#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], f[maxn], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    int i = 1, j = 2;
    while (1)
    {
        while (f[i] == 1 && i <= n) i++;
        while ((f[j] == 1 || a[i] == a[j]) && j <= n) j++;
        if (j == n+1) break;
        f[i] = 1, f[j++] = 2;
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << " ";
    for (int i = 1; i <= n; i++)
        if (f[i] != 1) ans++;
    cout << ans;
    return 0;
}