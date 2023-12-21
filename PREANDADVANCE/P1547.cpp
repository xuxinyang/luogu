#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
const int maxm = 1e4+5;
const int inf = 0x3f3f3f3f;
int n, m, closest[maxn], lowcost[maxn];
int head[maxn], tot;
bool s[maxn], vis[maxn][maxn];
struct Edge
{
    int to, next, w;
};
Edge edges[maxm<<1];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, head[u], w};
    head[u] = tot;
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        if (vis[u][v] == 0 && vis[v][u] == 0)
        {
            add(u, v, w), add(v, u, w);
            vis[u][v] = vis[v][u] = 1;
        }
        else 
        {
            for (int i = head[u]; i; i = edges[i].next)
            {
                if (edges[i].to == v && edges[i].w > w)
                {
                    edges[i].w = w;
                }
            }
            for (int i = head[v]; i; i = edges[i].next)
            {
                if (edges[i].to == u && edges[i].w > w)
                {
                    edges[i].w = w;
                }
            }
        }
    }
    memset(lowcost, 0x3f, sizeof(lowcost));
    lowcost[1] = 0;
    s[1] = 1;
    // 先找出1号节点能够到达的节点
    for (int i = head[1]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        lowcost[v] = edges[i].w;
        closest[v] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int tmp = inf;
        int t = 1;
        // 找最小
        for (int j = 1; j <= n; j++)
        {
            if (!s[j] && lowcost[j] < tmp)
            {
                t = j;
                tmp = lowcost[j];
            }
        }
        if (t == 1) break;  // 找不到，退出
        s[t] = true;    // 找到了，加入
        for (int j = head[t]; j; j = edges[j].next)
        {
            int v = edges[j].to;
            if (!s[v] && edges[j].w < lowcost[v])
            {
                lowcost[v] = edges[j].w;
                closest[v] = t;
            }
        }
    }
    cout << *max_element(lowcost + 1, lowcost + n + 1);
    return 0;
}