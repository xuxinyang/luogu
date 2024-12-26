#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct Edge
{
    int to, next;
};
Edge edge[maxn<<1];
int head[maxn], tot, n, a[maxn], ans = 0, son[maxn];
void add(int u, int v)
{
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}
void dfs(int u, int fa)
{
    son[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa) continue;
        if (son[v]) {son[u] += son[v]; continue;}
        if (a[v] < a[u]) dfs(v, u);
        son[u] += son[v];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!son[i]) dfs(i, 0);
        ans = max(son[i], ans);
    }
    // for (int i = 1; i <= n; i++) cout << son[i] << " ";
    cout << ans;
    return 0;
}