#include <bits/stdc++.h>
using namespace std;
constexpr int INF = INT_MAX;
constexpr int N = 5e4+5;
int n, m, tot;
int dis[N], vis[N], head[N], cnt[N];
struct Edge {
    int nxt, to, dis;
} edges[N];
void add(int u, int v, int w)
{
    edges[++tot] = {head[u], v, w};
    head[u] = tot;
}
bool spfa() // 找负环
{
    queue<int> q;
    for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = 0;
    q.push(0);
    dis[0] = 0, vis[0] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = edges[i].nxt)
        {
            int v = edges[i].to, w = edges[i].dis;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    cnt[v]++;
                    if (cnt[v] > n + 1) return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(v, u, w);
    }
    for (int i = 1; i <= n; i++) add(0, i, 0);
    if (!spfa())
    {
        for (int i = 1; i <= n; i++) cout << dis[i] << " ";
    }
    else cout << "NO";
    return 0;
}