#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
const int mod = 1e9;
ll n, a[N], f[N], ans;
int main()
{
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i-1]*i % mod;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u]++, a[v]++;
    }
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * f[a[i]-1] % mod;
    }
    ans = ans * 2 * (n-1) % mod;
    cout << ans;
    return 0;
}