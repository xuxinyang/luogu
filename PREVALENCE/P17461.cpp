#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 1e5+5;
constexpr int mod = 998244353;
int n, m, dep[N];
vector<int> ve[N];
ll ans = 1;
bool vis[N];
void dfs(int u, int fa)
{
    vis[u] = 1;
    for (auto v: ve[u])
    {
        if (v == fa) continue;
        if (!vis[v])
        {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
        else if (dep[v] < dep[u])
        {
            int len = dep[u] - dep[v] + 1;
            ans = ans * len % mod;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1, 0);
    cout << ans;
    return 0;
}