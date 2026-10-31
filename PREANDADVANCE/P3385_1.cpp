#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e3+5;
constexpr int M = 2e4+5;
constexpr int inf = 1e9;
using ll = long long;
int n, m, tot;
int dis[N], vis[N], head[N], cnt[N];
struct Edge {
    int nxt, to, dis;
} edges[M];
void add(int u, int v, int w)
{
    edges[++tot] = {head[u], v, w};
    head[u] = tot;
}
bool spfa() // spfa 算法，返回值为 1 表示有负环
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    q.push(1);
    dis[1] = 0;
    vis[1] = 1;
    cnt[1]++;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = edges[i].nxt)
        {
            int v = edges[i].to;
            if (dis[v] > dis[u] + edges[i].dis)
            {
                dis[v] = dis[u] + edges[i].dis;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    cnt[v]++;
                    if (cnt[v] > n) return 1;
                }
            }
        }
    }
    return 0;
}
void init()
{
    memset(dis, 0, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    memset(edges, 0, sizeof edges);
    memset(head, 0, sizeof head);
    tot = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        init();
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
            if (w >= 0) add(v, u, w);
        }
        if (spfa()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}