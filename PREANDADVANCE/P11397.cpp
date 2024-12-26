#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, k, a[maxn], head[maxn], tot, dep[maxn], ans;
struct Edge
{
    int to, next;
}edge[maxn<<1];
void add(int u, int v)
{
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}
void dfs(int u, int fa, int k)
{
    if (a[u] && k <= 0) return;
    dep[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa) continue;
        if (a[v]) dfs(v, u, k-1);
        else dfs(v, u, k);
        dep[u] = max(dep[u], dep[v]+1);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(dep, 0, sizeof(dep));
        dfs(i, 0, k);
        ans = max(ans, dep[i]);
    }
    cout << ans;
    return 0;
}