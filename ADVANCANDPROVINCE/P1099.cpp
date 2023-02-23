#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
const int maxm = 605;
int n, m, x, y, z, tot, top, k, ans = INT_MAX;
int dist[maxn], fa[maxn], head[maxn];
bool flag[maxn];
struct Edge
{
    int to, w, next;
};
Edge edges[maxm];
void add(int u, int v, int w)
{
    edges[++tot] = (Edge){v, w, head[u]};
    head[u] = tot;
}

void dfs(int f, int x)
{
    fa[x] = f;
    if (dist[x] > dist[k]) k = x;
    for (int i = head[x]; i; i = edges[i].next)
    {
        int to = edges[i].to;
        if (to == f || flag[to]) continue;
        dist[to] = dist[x] + edges[i].w;
        dfs(x, to);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z); add(y, x, z);
    }
    
    dist[1] = 1, dfs(0, 1);
    dist[k] = 0, dfs(0, k);
    
    top = k;
    for (int i = top, j = top, l = 1, r = 0; i; i = fa[i])
    {
        while (dist[j] - dist[i] > m) j = fa[j];
        x = max(dist[top] - dist[j], dist[i]);
        ans = min(ans, x);
    }
    for (int i = top; i; i = fa[i]) flag[i] = 1;
    for (int i = top; i; i = fa[i])
    {
        k = i, dist[k] = 0;
        dfs(fa[i], i);
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }
    cout << ans << endl;
    return 0;
}