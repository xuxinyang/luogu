#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+5;
constexpr int M = 1e3+5;
constexpr int INF = 1e9;

int n, q, a[N], r[N];
int pos[M], tot, key[M], cnt;
int f[M][M];    // f[k][i]: 表示终点为 key[k] 时，从 pos[i] 出发的最短距离
int g[M][M];    // g[k][i]: 前 i 个引用点中 f[k][j]-pos[j] 的最小值
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        if (r[i]) pos[++tot] = i, key[++cnt] = r[i];
    }
    key[++cnt] = 1;
    sort(key+1, key+cnt+1);
    cnt = unique(key+1, key+cnt+1)-key-1;
    for (int k = 1; k <= cnt; k++)
    {
        int y = key[k];
        int mn = INF;
        for (int i = 1; i <= tot; i++)
        {
            int x = pos[i];
            if (x < y)
            {
                f[k][i] = INF;
                g[k][i] = mn;
                continue;
            }
            f[k][i] = x - y;
            if (r[x] >= y)
            {
                int z = r[x];
                int p = upper_bound(pos+1, pos+tot+1, z) - pos - 1;
                int d = z - y;
                if (p >= 1 && g[k][p] != INF) d = min(d, z + g[k][p]);
                f[k][i] = min(f[k][i], 1 + d);
            }
            mn = min(mn, f[k][i] - x);
            g[k][i] = mn;
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int k = lower_bound(key+1, key+cnt+1, y) - key;
        if (k > cnt || key[k] > x)
        {
            cout << x - y << "\n";
            continue;
        }
        int z = key[k];
        int ans = x - z;
        int p = upper_bound(pos+1, pos + tot + 1, x) - pos - 1;
        if (p >= 1 && g[k][p] != INF) ans = min(ans, x + g[k][p]);
        ans += z - y;
        cout << ans << "\n";
    }
    return 0;
}