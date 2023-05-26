#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
int n, u, v, a[maxn], f[maxn], ans = INT_MIN;
vector<int> ve[maxn];
void dfs(int u, int fa)
{
    f[u] = a[u];
    for (int i = 0; i < ve[u].size(); i++)
    {
        int v = ve[u][i];
        if (v == fa) continue;
        dfs(v, u);
        if (f[v] >= 1) f[u] += f[v];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}