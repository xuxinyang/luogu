#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, dep[N];
vector<int> ve[N];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for (int v : ve[u])
    {
        if (v == fa) continue;
        dfs(v, u);
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
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] & 1) cnt1++;
        else cnt2++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dep[i]&1) cout << cnt1 << " ";
        else cout << cnt2 << " ";
    }
    return 0;
}