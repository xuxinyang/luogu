#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, a[maxn], f[maxn], g[maxn], ans;
vector<int> ve[maxn], vf[maxn];
queue<int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        ve[x].push_back(y);
        vf[y].push_back(x);
        if (z == 2)
        {
            ve[y].push_back(x);
            vf[x].push_back(y);
        }
    }
    q.push(1);
    memset(f, 0x3f, sizeof(f));
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        f[u] = min(f[u], a[u]);
        for (int i = 0; i < ve[u].size(); i++)
        {
            if (f[u] < f[ve[u][i]])
            {
                f[ve[u][i]] = f[u];
                q.push(ve[u][i]);
            }
        }
    }
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        g[u] = max(g[u], a[u]);
        for (int i = 0; i < vf[u].size(); i++)
        {
            if (g[u] > g[vf[u][i]])
            {
                g[vf[u][i]] = g[u];
                q.push(vf[u][i]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, g[i] - f[i]);
    }
    cout << ans;
    return 0;
}