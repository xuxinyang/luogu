// P1941: 飞扬的小鸟
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 1e3+5;
const int inf = 0x3f3f3f3f;
int n, m, k, h[maxn], l[maxn];
int x[maxn], y[maxn], f[maxn][maxm<<1], ans;
bool flag[maxn];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        h[i] = m, l[i] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        int id, low, high;
        cin >> id >> low >> high;
        flag[id] = 1;
        h[id] = high-1, l[id] = low+1;
    }
    memset(f, 0x3f, sizeof(f));
    for (int j = 1; j <= m; j++) f[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = x[i]+1; j <= x[i]+m; j++)
            f[i][j] = min(f[i-1][j-x[i]]+1, f[i][j-x[i]]+1);
        for (int j = m+1; j <= m+x[i]; j++)
            f[i][m] = min(f[i][m], f[i][j]);
        for (int j = 1; j <= m-y[i]; j++)
            f[i][j] = min(f[i][j], f[i-1][j+y[i]]);
        for (int j = 1; j < l[i]; j++) f[i][j] = inf;
        for (int j = h[i]+1; j <= m; j++) f[i][j] = inf;
    }
    
    ans = inf;
    for (int j = 1; j <= m; j++) ans = min(ans, f[n][j]);
    if (ans < inf)
    {
        cout << "1\n" << ans << endl;
        return 0;
    }   
    int i, j;
    for (i = n; i >= 1; i--)
    {
        for (j = 1; j <= m; j++)
            if (f[i][j] < inf) break;
        if (j <= m) break;
    }
    ans = 0;
    for (j = 1; j <= i; j++) if (flag[j]) ans++;
    cout << "0\n" << ans << endl;
    return 0;
}