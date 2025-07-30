#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, m, f[N][25], s[N][25], dep[N];
vector<int> ve[N];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    if (!ve[u].empty()) s[u][0] = ve[u][0];
    else s[u][0] = u;
    for (auto v : ve[u]) dfs(v, u);
}
void init()
{
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (f[i][j-1] != 0) f[i][j] = f[f[i][j-1]][j-1];
        }
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            s[i][j] = s[s[i][j-1]][j-1];
        }
    }
}
int up(int u, int k)
{
    if (u == 1) return 1;
    int dis = dep[u]-1;
    if (k >= dis) return 1;
    for (int i = 0; i <= 20; i++)
    {
        if ((k>>i)&1) u = f[u][i];
    }
    return u;
}
int down(int u, int k)
{
    for (int i = 0; i <= 20; i++)
    {
        if ((k>>i)&1) u = s[u][i];
    }
    return u;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 20; j++) s[i][j] = i;
    }
    f[1][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        f[i][0] = x;
        ve[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) sort(ve[i].begin(), ve[i].end());
    dfs(1, 0);
    init();
    for (int i = 1; i <= m; i++)
    {
        int u, k;
        cin >> u >> k;
        int ans = u;
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            if (x > 0) ans = up(ans, x);
            else ans = down(ans, -x); 
        }
        cout << ans << "\n";
    }
    return 0;
}