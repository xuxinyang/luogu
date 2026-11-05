#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e3+5;
constexpr int inf = INT_MAX;
int n, cnt, lst[N], h[N];   // lst[i] 表示 dis[i] 对应边的七点，数组 h 与下方，数组 e 存储图
int dis[N], d[N][N];    // 数组 d 为原图
bool vis[N];
struct Edge {
    int nxt, to, val;
} e[N<<1];  // 用于存储最小生成树的数组
void add(int u, int v, int w) {
    e[++cnt] = {h[u], v, w};
    h[u] = cnt;
}
void prim() // prim 算法求最小生成树
{
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[1] = 0, dis[0] = inf;
    int tot = 0;
    while (1)
    {
        int u = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dis[i] < dis[u]) u = i;
        }
        if (!u) break;
        vis[u] = 1;
        if (u != 1) add(u, lst[u], dis[u]), add(lst[u], u, dis[u]);
        for (int v = 1; v <= n; v++)
        {
            if (vis[v]) continue;
            int w = d[u][v];
            if (dis[v] > w) dis[v] = w, lst[v] = u;
        }
    }
}
void dfs(int u, int fa) // bfs 求两点之间距离，用于验证
{
    for (int i = h[u]; i; i = e[i].nxt)
    {
        int v = e[i].to, w = e[i].val;
        if (v == fa) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
            if (i != j && d[i][j] == 0)
            {
                cout << "NO";
                return 0;
            }
            if (i == j && d[i][j] != 0) 
            {
                cout << "NO";
                return 0;
            }
        }
    }
    prim();
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 0;
        dfs(i, 0);
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] != d[i][j])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}