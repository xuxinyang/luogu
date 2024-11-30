#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int maxm = 205;
const int inf = 1e9;
int n, m, l, ans;
int t[maxn], g[maxn][maxm];
int main()
{
    cin >> n >> m;
    l = m*2;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    ans = inf;
    for (int i = 1; i <= n; i++)
    {
        g[i][0] = inf;
        for (int j = 0; j <= min(t[i]-t[i-1]-m, m-1); j++)
        {
            g[i][0] = min(g[i][0], g[i-1][j]);
        }
        for (int j = 1; j < l; j++)
        {
            g[i][j] = min(g[i][j-1], 
            t[i]+j-t[i-1]-m>=0 && t[i]+j-t[i-1]-m<l?g[i-1][t[i]+j-t[i-1]-m]:inf);
        }
        for (int j = 0; j < l; j++)
        {
            g[i][j] = min(g[i][j], t[i]+j-t[i-1]<l?g[i-1][t[i]+j-t[i-1]]:inf)+j;
        }
    }
    for (int i = 0; i < m; i++) ans = min(ans, g[n][i]);
    cout << ans;
    return 0;
}