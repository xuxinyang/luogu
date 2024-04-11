#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxm = maxn*maxn;
const int maxl = 10;
int t, n, q, cnt, root, deep[maxn], head[maxn], to[maxm], nxt[maxm], p[maxn][maxl];
bool vis[maxn];
void add(int u, int v)
{
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
void dfs(int u)
{
    for (int i = head[u]; i; i = nxt[i])
    {
        deep[to[i]] = deep[u] + 1;
        p[to[i]][0] = u;
        dfs(to[i]);
    }
}
int lca(int a, int b)
{
    if (deep[a] < deep[b]) swap(a, b);
    int l = 0;
    for (; (1 << l) <= deep[a]; l++);
    l--;
    for (int i = l; i >= 0; i--)
        if (deep[a]-(1<<i)>=deep[b]) a = p[a][i];
    if (a == b) return a;
    for (int i = l; i >= 0; i--)
    {
        if (p[a][i] != p[b][i])
        {
            a = p[a][i];
            b = p[b][i];
        }
    }
    return p[a][0];
}
int main()
{
    scanf("%d", &t);
    for (int id = 1; id <= t; id++) 
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int m;
            scanf("%d", &m);
            for (int j = 1; j <= m; j++)
            {
                int v;
                scanf("%d", &v);
                add(i, v);
                vis[v] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                root = i;
                break;
            }
        }
        deep[root] = 0;
        dfs(root);
        for (int j = 1; (1<<j)<=n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
        scanf("%d", &q);
        printf("Case %d:\n", id);
        while (q--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", lca(a, b));
        }
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
    }   
    return 0;
}