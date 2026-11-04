// 单调队列优化
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e5+5;
constexpr int inf = INT_MAX;
struct Edge {
    int nxt, to, val;
} e[N];
struct Node {
    int pos, dis;
    friend bool operator < (Node A, Node B){
        return A.dis > B.dis;
    }
} tmp;
priority_queue<Node> pq;
int head[N], cnt, dis[N], tot, ans, n, m;
bool vis[N];
void add(int u, int v, int w)
{
    e[++cnt] = {head[u], v, w};
    head[u] = cnt;
}
void prim() // prim 算法
{
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[1] = 0;
    tmp.dis = 0, tmp.pos = 1;
    pq.push(tmp);
    while (!pq.empty())
    {
        tmp = pq.top(); // 取出 dis 最小的点
        pq.pop();
        int u = tmp.pos, d = tmp.dis;
        if (vis[u]) continue;   // 如果已经标记过就跳过
        tot++; vis[u] = 1; ans += dis[u];
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to, w = e[i].val;
            if (dis[v] > w)
            {
                tmp.dis = dis[v] = w;
                tmp.pos = v;
                pq.push(tmp);
            }
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