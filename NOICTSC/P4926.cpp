#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int inf = INT_MAX;
const double eps = 1e-5;
int n, s, t, head[maxn], cnt[maxn], tot;
bool vis[maxn];
double dist[maxn], ans;
struct Edge
{
    int to, next, kind;
    double w;
};
Edge edges[maxn << 2];
void add(int u, int v, double w, int kind)
{
    edges[++tot] = Edge{v, head[u], kind, w};
    head[u] = tot;
}
bool spfa(double x)
{
    for (int i = 0; i <= n; i++) 
    {
        dist[i] = -inf;
        cnt[i] = 0;
        vis[i] = 0;
    }
    dist[n+1] = 0, vis[n+1] = 1;
    queue<int> q;
    q.push(n+1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        vis[cur] = 0;
        for (int i = head[cur]; i; i = edges[i].next)
        {
            double w = edges[i].w;
            int v = edges[i].to, kind = edges[i].kind;
            if (kind == 1) w = log2(w - x);
            if (kind == 2) w = -log2(w + x);
            if (dist[v] < dist[cur] + w)
            {
                dist[v] = dist[cur] + w;
                cnt[v] = cnt[cur] + 1;
                if (cnt[v] >= n + 2) return true;
                else if (!vis[v]) vis[v] = 1, q.push(v);
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> s >> t;
    double k, l = 0, r = 10;
    for (int i = 0; i <= n; i++) add(n+1, i, 0, 3);
    for (int i = 1; i <= s; i++)
    {
        int op, a, b;
        cin >> op >> a >> b >> k;
        add(b, a, k, op);
        if (op == 1) r = fmin(r, k);
    }
    for (int i = 1; i <= t; i++)
    {
        int c;
        cin >> c >> k;
        add(0, c, log2(k), 3), add(c, 0, -log2(k), 3);
    }
    if (!spfa(0)) cout << -1 << endl;
    else
    {
        while (r - l > eps)
        {
            double mid = (l + r) / 2.0;
            if (spfa(mid)) ans = mid, l = mid;
            else r = mid;
        }
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}