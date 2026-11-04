// Prim 算法实现
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e5+5;
constexpr int inf = INT_MAX;
struct Edge {
    int nxt, to, val;
} e[N];
int head[N], cnt, dis[N], tot, ans;
bool vis[N];
void add(int u, int v, int w)
{
    e[++cnt] = {head[u], v, w};
    head[u] = cnt;
}
int n, m;
void prim() // prim 算法
{
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[1] = 0, dis[0] = inf;
    while (1)
    {
        int u = 0;
        for (int i = 1; i <= n; i++) // 找最小
        {
            if (!vis[i] && dis[i] < dis[u]) u = i;
        }
        if (!u) break;
        tot++, vis[u] = 1, ans += dis[u];  // 将边加入生成树并将点做标记
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to, w = e[i].val;
            if (dis[v] > w) dis[v] = w; // 更新数组 dis
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    prim();
    if (tot == n) cout << ans;
    else puts("orz");
    return 0;
}