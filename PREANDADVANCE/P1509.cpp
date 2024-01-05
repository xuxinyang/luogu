#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, r, rmb[maxn], rp[maxn], tim[maxn];
int f[maxn][maxn], g[maxn][maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> rmb[i] >> rp[i] >> tim[i];
    cin >> m >> r;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= rmb[i]; j--)
        {
            for (int k = r; k >= rp[i]; k--)
            {
                if (f[j][k] < f[j-rmb[i]][k-rp[i]] + 1)
                {
                    f[j][k] = f[j-rmb[i]][k-rp[i]] + 1;
                    g[j][k] = g[j-rmb[i]][k-rp[i]] + tim[i];
                }
                else if (f[j][k] == f[j-rmb[i]][k-rp[i]] + 1)  // MZ数量一致的前提下优先选择时间最少的方案
                {
                    g[j][k] = min(g[j][k], g[j-rmb[i]][k-rp[i]] + tim[i]); 
                }
            }
        }
    }
    cout << g[m][r];
    return 0;
}