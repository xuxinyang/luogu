#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
struct Edge
{
    int to, next, w;
};
Edge edges[maxn<<2];
int n, m, head[maxn], tot, vis[maxn], cnt[maxn];
long long ans, dist[maxn];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, head[u], w};
    head[u] = tot;
} 
queue<int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int op, x, y, z;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> z;
            add(y, x, z);
        }
        else if (op == 2)
        {
            cin >> x >> y >> z;
            add(x, y, -z);
        }
        else
        {
            cin >> x >> y;
            add(x, y, 0), add(y, x, 0);
        }
    }
    for (int i = 1; i <= n; i++) add(0, i, 0);
    memset(dist, -0x3f, sizeof(dist));
    dist[0] = 0;
    vis[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        vis[cur] = 0;
        for (int i = head[cur]; i; i = edges[i].next)
        {
            int v = edges[i].to, w = edges[i].w;
            if (dist[cur] + w > dist[v])
            {
                dist[v] = dist[cur] + w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    if (++cnt[v] >= n)
                    {
                        cout << "No";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes";
    return 0;
}