#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll f[205][205] = {1}, sum[205][205], n, m, t;
char a[1005], b[205];
int main()
{
    cin >> n >> m >> t;
    cin >> a >> b;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            for (int k = t; k >= 1; k--)
                f[j][k] = (f[j][k] + (sum[j][k] = a[i-1]==b[j-1] ? sum[j-1][k] + f[j-1][k-1] : 0)) % mod;
    cout << f[m][t];
    return 0;
}