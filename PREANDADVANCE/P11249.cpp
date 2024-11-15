#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int t, a[maxn], n, s, start, dep[maxn];
vector<int> ve[maxn];
void dfs(int x, int fa)
{
    dep[x] = dep[fa] + (a[x] == 1);
    for (int v: ve[x])
    {
        if (v == fa) continue;
        dfs(v, x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i]) s++, start = i;
            ve[i].clear(); dep[i] = 0;
        }
        int u, v;
        for (int i = 1; i <= n-1; i++)
        {
            cin >> u >> v;
            ve[u].push_back(v), ve[v].push_back(u);
        }
        dfs(1, 0);
        int mx = -1, root = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dep[i] > mx) mx = dep[i], root = i;
        }
        memset(dep, 0, sizeof(dep));
        dfs(root, 0);
        mx = -1;
        for (int i = 1; i <= n; i++) mx = max(mx, dep[i]);
        if (mx == s) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}