#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, q, tot;
int a[205], f[205][205];
void update(int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (f[i][j] > f[i][k] + f[k][j])
                f[i][j] = f[j][i] = f[i][k] + f[k][j];
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < n; i++) f[i][i] = 0;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = w;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> u >> v >> w;
        while (a[tot] <= w && tot < n)
        {
            update(tot);
            tot++;
        }
        if (a[u] > w || a[v] > w) cout << -1 << "\n";
        else
        {
            if (f[u][v] == inf) cout << -1 << "\n";
            else cout << f[u][v] << "\n";
        }
    }
    return 0;
}