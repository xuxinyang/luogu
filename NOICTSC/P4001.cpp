#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxn = 1e7 + 5;
struct Edge
{
    int to, next, w;
};
struct Point
{
    int dist;
    int id;
    Point(int x, int y)
    {
        id = x, dist = y;
    }
    bool operator<(const Point A) const
    {
        return dist > A.dist;
    }
};
Edge edges[maxn];
int head[maxn], n, m, tot, s, t;
int deep[maxn], dis[maxn], book[maxn];
priority_queue<Point> pq;
void add(int u, int v, int w)
{
    edges[++tot] = (Edge){v, head[u], w};
    head[u] = tot;
}

void dijkstra(int s)
{
    for (int i = 1; i <= t; i++)
        dis[i] = inf;
    dis[s] = 0;
    pq.push(Point(s, 0));
    while (!pq.empty())
    {
        int u = pq.top().id;
        pq.pop();
        if (book[u])
            continue;
        book[u] = 1;
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (dis[v] > dis[u] + edges[i].w)
            {
                dis[v] = dis[u] + edges[i].w;
                if (!book[v])
                    pq.push(Point(v, dis[v]));
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    t = (2 * n - 2) * (m - 1) + 1;
    int tmp, t1, t2;
    // row start
    for (int i = 1; i < m; i++)
    {
        cin >> tmp;
        add(i * 2, t, tmp);
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cin >> tmp;
            t1 = 2 * (i - 2) * (m - 1) - 1 + 2 * j;
            t2 = 2 * (i - 1) * (m - 1) + 2 * j;
            add(t1, t2, tmp);
            add(t2, t1, tmp);
        }
    }
    for (int i = 1; i < m; i++)
    {
        cin >> tmp;
        t1 = 2 * (n - 2) * (m - 1) - 1 + 2 * i;
        add(s, t1, tmp);
    }
    // row end
    // col start
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tmp;
            t1 = 2 * (i - 1) * (m - 1) - 1 + 2 * j;
            t2 = t1 - 1;
            if (j == 1)
                add(s, t1, tmp);
            else if (j == m)
                add(t2, t, tmp);
            else
            {
                add(t1, t2, tmp);
                add(t2, t1, tmp);
            }
        }
    }
    // col end
    // bias start
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cin >> tmp;
            t1 = 2 * (i - 1) * (m - 1) - 1 + 2 * j;
            t2 = t1 + 1;
            add(t1, t2, tmp);
            add(t2, t1, tmp);
        }
    }
    // bias end
    dijkstra(0);
    cout << dis[t];
    return 0;
}