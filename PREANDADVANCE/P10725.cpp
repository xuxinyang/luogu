#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], head[maxn], tot, d[maxn], ans;
struct Edge
{
    int to, from, next;
};
Edge edges[maxn<<1];
void add(int u, int v)
{
    edges[++tot] = {v, u, head[u]};
    head[u] = tot;
}
void dfs(int u, int fa)
{
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}
void calc(int u, int fa, int t, int s)
{
    if (a[u] == t) ans = max(ans, s);
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == fa) continue;
        calc(v, u, t, s+1);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    int id1 = 0, id2 = 0;
    int mx1 = 0, mx2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            if (d[i] >= mx1) mx1 = d[i], id1 = i;
        }    
        else 
        {
            if (d[i] >= mx2) mx2 = d[i], id2 = i;
        }
    }
    if (id1) calc(id1, 0, 1, 0);
    if (id2) calc(id2, 0, 0, 0);
    cout << ans;
    return 0;
}