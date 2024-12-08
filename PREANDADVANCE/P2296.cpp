#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 2e5+5;
struct Edge
{
    int to, next;
};
Edge edges[maxm], rev[maxm];
int head[maxn], rh[maxn], tot, cnt, n, m, s, t, ans;
bool use[maxn], vis[maxn];
struct Node
{
    int id, step;
};
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
    rev[++cnt] = {u, rh[v]};
    rh[v] = tot;
}
void dfs(int u, int fa)
{
    for (int i = rh[u]; i; i = rev[i].next)
    {
        int v = rev[i].to;
        if (!use[v])
        {
            use[v] = 1;
            dfs(v, u);
        }
    }
}
queue<Node> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    cin >> s >> t;
    use[t] = 1;
    dfs(t, 0);  // 反向边标记
    q.push({s, 0});
    vis[s] = 1;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.id == t)
        {
            cout << cur.step;
            return 0;
        }
        for (int i = head[cur.id]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (v == s && v == cur.id)  // 起点自环
            {
                cout << -1;
                return 0;
            }
            // 检查当前结点所连接的结点是否存在无法直/间连t的结点
            bool flag = 0;
            for (int j = head[v]; j; j = edges[j].next)
            {
                int p = edges[j].to;
                if (!use[p])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;
            if (!vis[v] && use[v])
            {
                vis[v] = 1;
                q.push({v, cur.step+1});
            }
        }
    }
    cout << -1;
    return 0;
}