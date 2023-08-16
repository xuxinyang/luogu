#include <bits/stdc++.h>
using namespace std;
const int maxn = 225;
const int maxm = 505;
int d, p, c, f, s, u, v, w, ans;
int head[maxn], tot, dis[maxn], cnt[maxn];
bool vis[maxn];
priority_queue<int, vector<int>, greater<int> > pq;
struct Edge
{
    int to, next, from, w;
};
Edge edges[maxm];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, head[u], u, w};
    head[u] = tot;
}
void spfa()
{
    pq.push(s);
    dis[s] = d, vis[s] = 1, cnt[s]++;
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        vis[u] = 0;
        if (++cnt[u] > c)
        {
            cout << -1;
            return;
        }
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (dis[v] < dis[u] + edges[i].w)
            {
                dis[v] = dis[u] + edges[i].w;
                if (!vis[v]) pq.push(v), vis[v] = 1;
            }
        }
    }
}
int main()
{
    cin >> d >> p >> c >> f >> s;
    for (int i = 1; i <= p; i++)
    {
        cin >> u >> v;
        add(u, v, d);
    }
    for (int i = 1; i <= f; i++)
    {
        cin >> u >> v >> w;
        add(u, v, d-w);
    }
    spfa();
    for (int i = 1; i <= c; i++) ans = max(ans, dis[i]);
    cout << ans << endl;
    return 0;
}