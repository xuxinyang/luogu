#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+5;
int n, q, d[N], c[N], rmax[N][20], f[N][20], g[N][20], log_2[N];
int query(int A, int B)
{
    int x = log_2[B-A+1];
    return max(rmax[A][x], rmax[B-(1<<x)+1][x]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> d[i] >> c[i];
    for (int i = 2; i <= n; i++) log_2[i] = log_2[i>>1]+1;
    for (int i = 1; i <= n; i++) rmax[i][0] = d[i];
    for (int j = 1; (1<<j) <= n; j++)
    {
        for (int i = 1; i <= n-(1<<j)+1; i++)
        {
            rmax[i][j] = max(rmax[i][j-1], rmax[i+(1<<j-1)][j-1]);
        }
    }
    c[n+1] = 1e9;
    for (int i = 1; i < n; i++)
    {
        int l = i+1, r = n+1, mid;
        while (l < r)
        {
            mid = l + r >> 1;
            if (query(i+1, mid) <= d[i]) l = mid + 1;
            else r = mid;
        }
        f[i][0] = l, g[i][0] = c[f[i][0]];
    }
    f[n][0] = n + 1, g[n][0] = c[f[n][0]];
    for (int t = 1; t <= 16; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i][t] = f[f[i][t-1]][t-1];
            g[i][t] = g[i][t-1] + g[f[i][t-1]][t-1];
        }
    }
    while (q--)
    {
        int r, v;
        cin >> r >> v;
        if (v > c[r])
        {
            v -= c[r];
            for (int t = 16; t >= 0; t--)
            {
                if (v > g[r][t])    // 水溢出流到 f[r][t] 号圆盘且还将继续溢出
                {
                    v -= g[r][t];
                    r = f[r][t];
                }
            }
            r = f[r][0];
        }
        if (r == n+1) r = 0;
        cout << r << "\n";
    }
    return 0;
}