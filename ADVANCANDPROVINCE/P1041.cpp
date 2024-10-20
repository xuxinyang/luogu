#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int n, m, ans;
struct Node
{
    int to, next;
} edges[maxn<<1];
int head[maxn], tot, fa[maxn], siz[maxn], deep[maxn], maxdep, in[maxn];
vector<int> ve[maxn];
inline void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
void dfs(int x, int f, int dep)
{
    fa[x] = f; siz[x] = 1; deep[x] = dep;
    maxdep = max(maxdep, dep);
    for (int i = head[x]; i; i = edges[i].next)
    {
        if (edges[i].to != f)
        {
            dfs(edges[i].to, x, dep+1);
            siz[x] += siz[edges[i].to];
        }
    }
}
void dfs2(int dep, int now)
{
    if (dep == maxdep + 1)
    {
        ans = min(ans, now);
        return;
    }
    for (int i = 0; i < ve[dep].size(); ++i)
    {
        if (in[fa[ve[dep][i]]]) in[ve[dep][i]] = 1;
        else in[ve[dep][i]] = 0;
    }
    bool flag = 1;
    for (int i = 0; i < ve[dep].size(); i++)
    {
        if (!in[ve[dep][i]]) flag = 0;
    }
    if (flag)
    {
        ans = min(ans, now);
        return;
    }
    for (int i = 0; i < ve[dep].size(); ++i)
    {
        if (in[ve[dep][i]]) continue;
        in[ve[dep][i]] = 1;
        dfs2(dep+1, now-siz[ve[dep][i]]);
        in[ve[dep][i]] = 0;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++) ve[deep[i]].push_back(i);
    ans = n;
    dfs2(2, n);
    cout << ans;
    return 0;
}