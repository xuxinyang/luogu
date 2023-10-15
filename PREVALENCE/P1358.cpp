#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int mod = 1e4 + 7;
#define ll long long
ll n, m, a[maxn], f[maxn][105], ans;
void init()
{
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= min(i, 100); j++)
        {
            if (j == 0 || j == i) f[i][j] = 1;
            else f[i][j] = (f[i-1][j-1] + f[i-1][j])%mod;
        }
    }
}
int main()
{
    cin >> n >> m;
    ans = 1;
    init();
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        ans = ans * f[n][a[i]] % mod;
        n -= a[i];
    }
    cout << ans;
    return 0;
}