#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, a[maxn], f[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = max(f[j], f[j-i]+a[i]);
    cout << f[n];
    return 0;
}