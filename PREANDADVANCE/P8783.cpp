#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k, a[505][505], sum[505][505];
ll ans;
ll calc_rec(ll n, ll m)
{
    return n * (n - 1) / 2 * m * (m - 1) / 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int p = i; p <= n; p++)
            {
                for (int q = m; q >= j; q--)
                {
                    if (sum[p][q]-sum[p][j-1]-sum[i-1][q]+sum[i-1][j-1] <= k)
                    {
                        ans += calc_rec(p-i+1, q-j+1);
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}