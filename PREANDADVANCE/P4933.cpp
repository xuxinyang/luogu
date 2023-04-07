#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int mod = 998244353;
const int offset = 2e4;
int n, h[maxn], f[maxn][offset<<1], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++)
    {
        ans++;
        for (int j = i-1; j; j--)
        {
            f[i][h[i]-h[j]+offset] += f[j][h[i]-h[j]+offset] + 1;
            f[i][h[i]-h[j]+offset] %= mod;
            ans += f[j][h[i]-h[j]+offset] + 1;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}