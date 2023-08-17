#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = maxn << 1;
int n, d, u, v, ans, head[maxn], tot;
bool vis[maxn];
struct Edge
{
    int to, next, from;
};
struct Pos
{
    int x, step;
};
Edge edges[maxm];
queue<Pos> q;
void add(int u, int v)
{
    edges[++tot] = Edge{v, head[u], u};
    head[u] = tot;
}
int main()
{
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    q.push(Pos{1, 0});
    vis[1] = 1;
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        for (int i = head[cur.x]; i; i = edges[i].next)
        {
            int to = edges[i].to;
            if (!vis[to] && cur.step + 1 <= d)
            {
                vis[to] = 1;
                ans++;
                q.push(Pos{to, cur.step + 1});
            }
        }
    }
    cout << ans;
    return 0;
}