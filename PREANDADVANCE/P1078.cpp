#include <bits/stdc++.h>
using namespace std;
int n, k, m, s, t, c[105], relation[105][105];
int head[105], tot, dist[105];
struct Edge
{
    int to, next, w;
};
Edge edges[105<<2];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, head[u], w};
    head[u] = tot;
}
queue<int> q;
void spfa()
{
    memset(dist, 0x7F, sizeof(dist));
    dist[n]
}
int main()
{
    cin >> n >> k >> m >> s >> t;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cin >> relation[i][j];
        }
    }
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    return 0;
}