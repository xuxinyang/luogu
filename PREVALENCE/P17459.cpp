#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3+5;
int n, m, in[N], out[N], ans[N], p;
vector<int> ve[N];
bool vis[N];
bool bfs(int ban)
{
    memset(vis, 0, sizeof vis);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i] && i != ban)
        {
            vis[i] = 1;
            q.push(i); 
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (out[u] == 0) return 1;
        for (int v : ve[u])
        {
            if (v == ban || vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
        in[v]++, out[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!bfs(i)) ans[++p] = i;
    }
    cout << p << "\n";
    for (int i = 1; i <= p; i++) cout << ans[i] << " ";
    return 0;
}