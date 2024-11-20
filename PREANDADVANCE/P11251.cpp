#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int n, head[maxn], tot, c[maxn], d[maxn], ans, root, res;
bool vis[maxn];
struct Edge
{
    int to, next;
} edges[maxm<<1];
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
void dfs(int u, int fa)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == fa) continue;
        d[v] = d[u] + 1;
        if (d[v] > ans)
        {
            ans = d[v], root = v;
        }
        dfs(v, u);
    }
}
int solve(int u)
{
    ans = -1, d[u] = 0;
    dfs(u, 0);
    ans = -1, d[root] = 0;
    dfs(root, 0);
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (!(c[u]^c[v])) continue;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) res = max(res, solve(i));
    }
    cout << res+1;
    return 0;
}