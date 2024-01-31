#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+5;

vector<pair<int, int>> G[maxn];
int d[maxn][105];
int vis[maxn][105];
struct Node
{
    int u, i, d;
    bool operator<(const Node &A) const
    {
        return d > A.d;
    }
};
priority_queue<Node> q;
int main()
{
    int maxn, m, k;
    scanf("%d%d%d", &maxn, &m, &k);
    while (m--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
    }
    memset(d, 0x3f, sizeof d);
    q.push({1, 0, d[1][0] = 0});
    while (q.size())
    {
        int u = q.top().u, i = q.top().i;
        q.pop();
        if (vis[u][i]) continue;
        vis[u][i] = 1;
        for (auto [v, w] : G[u])
        {
            int t = d[u][i], j = (i + 1) % k;
            if (t < w) t += (w - t + k - 1) / k * k;
            if (d[v][j] > t + 1) q.push({v, j, d[v][j] = t + 1});
        }
    }
    if (d[maxn][0] == INF) d[maxn][0] = -1;
    printf("%d", d[maxn][0]);
    return 0;
}