#include <bits/stdc++.h>
using namespace std;

const int maxm = 2e5 + 5;
int tot = 0, x, y, len, ans;
int h[maxm], dep[maxm], fa[maxm], Maxdep[maxm], deplen[maxm];
struct Edge
{
    int u, v, w, next;
} e[maxm];
void add(int u, int v, int w)
{
    tot++;
    e[tot].u = u, e[tot].v = v, e[tot].w = w;
    e[tot].next = h[u], h[u] = tot;
}
void dfs(int u, int f)
{
    if (len < dep[u])
        len = dep[u], y = u;
    for (int i = h[u]; i; i = e[i].next)
    {
        int v = e[i].v, w = e[i].w;
        if (f != v)
        {
            dep[v] = dep[u] + 1;
            fa[v] = u;
            dfs(v, u);
        }
    }
}
void dfs2(int u, int f)
{
    Maxdep[u] = dep[u];
    for (int i = h[u]; i; i = e[i].next)
    {
        int v = e[i].v, w = e[i].w;
        if (f != v)
        {
            dep[v] = dep[u] + 1;
            fa[v] = u;
            dfs2(v, u);
            Maxdep[u] = max(Maxdep[u], Maxdep[v]);
        }
    }
}
bool cmp(int a, int b) { return a > b; }
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v, 1);
        add(v, u, 1);
    } 
    x = 1, y = 0, len = 0;
    dfs(x, -1);
    memset(fa, 0, sizeof(fa));
    memset(dep, 0, sizeof(dep));
    len = 0;
    dfs(y, -1);
    int pos = y;
    for (int i = 1; i <= (dep[y] + 1) / 2; i++, pos = fa[pos]); 
    memset(fa, 0, sizeof(fa));
    memset(dep, 0, sizeof(dep));
    dfs2(pos, -1);
    for (int i = 1; i <= n; i++)
        deplen[i] = Maxdep[i] - dep[i];
    sort(deplen + 1, deplen + n + 1, cmp);
    for (int i = k + 1; i <= n; i++)
        ans = max(ans, deplen[i] + 1);
    cout << ans;
    return 0;
}