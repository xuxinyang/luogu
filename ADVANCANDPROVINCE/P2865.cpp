// 次短路
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+5;
constexpr int inf = INT_MAX;
struct Edge {
    int to, nxt, val;
} edges[N];
int head[N], cnt, dis[3][N], n, m;
void add(int from, int to, int value)
{
    edges[++cnt] = {to, head[from], value};
    head[from] = cnt;
}
struct Node {
    int pos, dis;
    friend bool operator < (Node A, Node B){
        return A.dis > B.dis;
    }
} tmp;
priority_queue<Node> pq;
void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        dis[0][i] = dis[1][i] = inf;
    }
    dis[0][1] = 0;
    tmp.dis = 0;
    tmp.pos = 1;
    pq.push(tmp);
    while (!pq.empty())
    {
        tmp = pq.top();
        pq.pop();
        int u = tmp.pos, d = tmp.dis;
        if (d > dis[1][u]) continue;    // 说明这条路已经无效，可以舍去
        for (int i = head[u]; i; i = edges[i].nxt)
        {
            int v = edges[i].to, w = edges[i].val;
            if (dis[0][v] > d + w)
            {
                dis[1][v] = dis[0][v];
                tmp.dis = dis[0][v] = d + w;
                tmp.pos = v;
                pq.push(tmp);
            }
            if (dis[1][v] > d + w && dis[0][v] < d + w)
            {
                tmp.dis = dis[1][v] = d + w;
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
    dijkstra();
    cout << dis[1][n];
    return 0;
}