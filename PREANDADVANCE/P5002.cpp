#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 5e4+5;
const int mod = 1e9+7;
int siz[maxn], ans[maxn];
vector<int> edges[maxn];
int n, m, r;
void add(int x, int y)
{
    edges[x].push_back(y);
    edges[y].push_back(x);
}
void dfs(int u, int fa)
{
    siz[u] = 1;
    int rest = 1;
    for (int p = 0; p < edges[u].size(); p++)
    {
        int v = edges[u][p];
        if (fa != v)
        {
            dfs(v, u);
            siz[u] = (siz[u] + siz[v]) % mod;
        }
    }
    for (int p = 0; p < edges[u].size(); p++)
    {
        int v = edges[u][p];
        if (fa != v)
            ans[u] = (ans[u] + (siz[u]-siz[v])*siz[v]%mod)%mod;
    }
    ans[u] = (ans[u] + siz[u]) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r >> m;
    int x, y;
    for (int p = 1; p <= n-1; p++)
    {
        cin >> x >> y;
        add(x, y);
    }
    dfs(r, 0);
    for (int p = 1; p <= m; p++)
    {
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}