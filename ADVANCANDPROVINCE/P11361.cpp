#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int t, n, ans;
int f[maxn][2], g[maxn][2], a[maxn], b[maxn], t1[maxn], t2[maxn];
char s[maxn];
void solve()
{
    cin >> n;
    ans = 0;
    for (int i = 0; i <= n+1; i++) 
        f[i][0] = f[i][1] = 0, g[i][0] = g[i][1] = 0;
    cin >> (s+1); for (int i = 1; i <= n; i++) a[i] = s[i]-'0';
    cin >> (s+1); for (int i = 1; i <= n; i++) b[i] = s[i]-'0';
    cin >> (s+1); for (int i = 1; i <= n; i++) t1[i] = s[i] - '0';
    cin >> (s+1); for (int i = 1; i <= n; i++) t2[i] = s[i] - '0';
    for (int i = n; i >= 1; i--)
    {
        f[i][0] += (a[i] == 0), f[i][1] += (a[i]==1);
        if (t1[i] && t1[i-1] && i > 1)
        {
            f[i-1][0] = f[i][0], f[i-1][1] = f[i][1];
            f[i][1] = f[i][0] = 0; 
        }
    }
    for (int i = n; i >= 1; i--)
    {
        g[i][0] += (b[i] == 0), g[i][1] += (b[i] == 1);
        if (t2[i] && t2[i-1] && i > 1)
        {
            g[i-1][0] = g[i][0], g[i-1][1] = g[i][1];
            g[i][1] = g[i][0] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i][0] && g[i][0]) ans++, f[i][0]--, g[i][0]--;
        else if (f[i][1] && g[i][1]) ans++, f[i][1]--, g[i][1]--;
        else if (f[i][0] && g[i][1]) f[i][0]--, g[i][1]--;
        else f[i][1]--, g[i][0]--;
        f[i+1][1] += f[i][1], f[i+1][0] += f[i][0];
        g[i+1][1] += g[i][1], g[i+1][0] += g[i][0];
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}