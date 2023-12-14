#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;
int n, head[N], tot, w[N], r1, r2;
bool vis[N];
struct Edge{
    int to, next;
};
Edge edges[N];
ll f[N][2], sum;
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
void find(int u, int rt)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == rt)
        {
            r1 = u, r2 = v;
            return;
        }
        if (vis[v]) continue;
        find(v, rt);
    }
}
ll dfs(int u, int rt)
{
    f[u][0] = 0; f[u][1] = w[u];
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v == rt) continue;
        dfs(v, rt);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
    return f[u][0];
}
int main()
{
    int u;
    cin >> n;
    for (int v = 1; v <= n; v++)
    {
        cin >> w[v] >> u;
        add(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            r1 = r2 = 0;
            find(i, i);
            if (r1)
            {
                ll res1 = dfs(r1, r1);
                ll res2 = dfs(r2, r2);
                sum += max(res1, res2);
            }
        }
    }
    cout << sum << endl;
    return 0;
}