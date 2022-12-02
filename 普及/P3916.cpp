#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
struct Edge
{
    int to, next;
} edges[maxm];
int head[maxn], tot, n, m, u, v;
int ans[maxn];
void add(int u, int v)
{
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}

void dfs(int u, int v)
{
    if (ans[v]) return;
    ans[v] = u;
    for (int i = head[v]; ~i; i = edges[i].next)
    {
        int to = edges[i].to;
        dfs(u, to);
    }
}
int main()
{
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(v, u);
    }
    for (int i = n; i; i--) dfs(i, i);
    for (int i = 1; i <= n; i++)
    {
        if (i != 1) cout << " ";
        cout << ans[i];
    }
    return 0;
}