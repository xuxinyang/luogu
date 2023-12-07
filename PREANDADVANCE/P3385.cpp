#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
const int maxm = 3e3+5;
struct Edge
{
    int to, next, w;
};
Edge edges[maxm<<1];
int t, n, m, head[maxn], tot;
queue<int> q;
int dis[maxn], vis[maxn], cnt[maxn];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, head[u], w};
    head[u] = tot;
}
void init()
{
    tot = 0;
    memset(edges, 0, sizeof(edges));
    memset(head, 0, sizeof(head));
    while (!q.empty()) q.pop();
}
bool spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    dis[1] = 0, vis[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to, w = edges[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return true;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    int u, v, w;
    while (t--)
    {
        init();
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            add(u, v, w);
            if (w >= 0) add(v, u, w);
        }
        if (spfa()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}