#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, m, a[N];
long long ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u]++, a[v]++;
    }
    // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    for (int i = 1; i <= n; i++)
    {
        ans += 1ll * a[i] * (a[i]-1) / 2;
    }
    cout << ans;
    return 0;
}