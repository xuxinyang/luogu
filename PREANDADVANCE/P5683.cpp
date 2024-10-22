#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3+5;
const int inf = 0x3f3f3f3f;
int n, m, head[maxn], tot, ans;
struct Edge
{
    int to, next;
} edges[maxn<<1];
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
int dis[4][maxn];
void bfs(int root, int dt[])
{
    dt[root] = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (dt[v] > dt[u] + 1)
                dt[v] = dt[u] + 1, q.push(v);
        }
    }
}
int main()
{
    int s1, t1, s2, t2;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    cin >> s1 >> t1 >> s2 >> t2;
    memset(dis, 0x3f, sizeof(dis));
    bfs(1, dis[1]);
    bfs(s1, dis[2]);
    bfs(s2, dis[3]);
    ans = inf;
    for (int i = 0; i <= n; i++)
        if (dis[1][i] + dis[2][i] <= t1 && 
        dis[1][i] + dis[3][i] <= t2)
            ans = min(ans, dis[1][i] + dis[2][i] + dis[3][i]);
    if (ans == inf) cout << -1;
    else cout << m-ans;
    return 0;
}