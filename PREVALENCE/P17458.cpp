#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e4+5;
vector<int> ve[N];
int n, son[N], ans;
void dfs(int u, int fa)
{
    son[u] = 1;
    for (auto v : ve[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        son[u] += son[v];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dfs(1, 0);
    ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, abs(n-2*son[i]));
    }
    cout << ans;
    return 0;
}