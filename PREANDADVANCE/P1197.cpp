#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+5;
int n, m, k, fa[N], vis[N], head[N], tot, at[N], ans[N];
struct Edge
{
    int to, next;
}edges[N<<1];
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fx] = fy;
}
void dfs(int x)
{
    vis[x] = 1;
    for (int i = head[x]; i; i = edges[i].next)
    {
        int t = edges[i].to;
        if (!vis[t])
        {
            merge(x, t);
            dfs(t);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u += 1, v += 1;
        add(u, v), add(v, u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> at[i]; 
        at[i] += 1;
        vis[at[i]] = 1;
    }
    // 倒着数，破环完了还剩多少个连通块，将删除边的操作逆向就是加边操作
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])    // 这个点还在，
        {
            cnt++;
            dfs(i); // 搜索标记
        }
    }
    ans[k+1] = cnt;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= k; i++) vis[at[i]] = 1;
    for (int i = k; i >= 1; i--)
    {
        vis[at[i]] = 0;
        cnt++;
        for (int j = head[at[i]]; j; j = edges[j].next)
        {
            int v = edges[j].to;
            if (!vis[v])
            {
                int fx = find(at[i]), fy = find(v);
                if (fx != fy)
                {
                    fa[fy] = fx;
                    cnt--;
                }
            }
        }
        ans[i] = cnt;
    } 
    for (int i = 1; i <= k+1; i++) cout << ans[i] << "\n";
    return 0;
}