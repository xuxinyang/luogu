#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
const int maxm = 1e5+5;
const long long inf = 1e15;
int head[maxn<<1], ver[maxm<<1], we[maxm << 1], nex[maxm<<1], tot, n;
int m, u, v, w;
ll ans;
void add(int u, int v, int w)
{
    ver[tot] = v;
    we[tot] = w;
    nex[tot] = head[u];
    head[u] = tot++;
}
struct node
{
    int x;
    ll dis;
    node() {}
    node(int _x, ll _dis) : x(_x), dis(_dis) {}
    bool operator > (const node &o) const
    {
        return dis > o.dis;
    }
};
priority_queue<node, vector<node>, greater<node> > q;
ll dis[maxn << 1];
void dijistra(int s)
{
    for (int i = 1; i <= n << 1; ++i) dis[i] = inf;
    dis[s] = 0;
    q.push(node(s, 0));
    while (!q.empty())
    {
        node cur = q.top(); q.pop();
        if (dis[cur.x] < cur.dis) continue;
        for (int i = head[cur.x]; ~i; i = nex[i])
        {
            if (dis[ver[i]] > cur.dis + we[i])
            {
                dis[ver[i]] = cur.dis + we[i];
                q.push(node(ver[i], dis[ver[i]]));
            }
        }
    }
}
int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v+n, u+n, w);
    }
    dijistra(1);
    for (int i = 2; i <= n; i++) ans += dis[i];
    dijistra(1 + n);
    for (int i = 2 + n; i <= n << 1; i++) ans += dis[i];
    cout << ans << endl;
    return 0;
}