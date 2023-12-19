#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
int n, m, head[maxn], tot, dist[maxn], cnt[maxn];
bool vis[maxn];
struct Edge
{
    int to, next, w;
};
Edge edges[maxn << 2];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, head[u], w};
    head[u] = tot;
}
bool spfa(int s)
{
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to, w = edges[i].w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                if (!vis[v])
                {
                    vis[v] = 1; 
                    if (++cnt[v] == n+1) return false;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) add(0, i, 0);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(y, x, z);
    }
    if (!spfa(0)) cout << "NO" << endl;
    else
        for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    return 0;
}