#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int mod = 1e9+7;
int t, n, m, a[maxn];
int c[maxn][maxn], ans, sum, s;
void init()
{
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        sum = 0;
        for (int i = 1; i <= m; i++) cin >> a[i], sum += a[i];
        ans = 1;
        s = n + (sum > n);
        for (int j = 1; j <= m; j++)
        {
            ans = (1ll*ans*c[s][a[j]]) % mod;
            s -= a[j];
        }
        cout << ans % mod << "\n";
    }
    return 0;
}