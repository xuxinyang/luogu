#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
const int maxm = 1e6+5;
int head[maxn], cnt;
ll ans[maxm];
bool vis[maxm];
int m, n, s;
struct Edge
{
    int to;
    int nxt;
    int w;
} edges[maxm];
struct priority
{
    ll ans;
    int id;
    bool operator < (const priority &x) const
    {
        return x.ans < ans;
    }
};
priority_queue<priority> q;
void add(int x, int y, int z)
{
    edges[++cnt].to = y;
    edges[cnt].w = z;
    edges[cnt].nxt = head[x];
    head[x] = cnt; 
}
int main()
{
    cin >> m >> n >> s;
    for (int i = 1; i <= n; i++) ans[i] = INT_MAX;
    ans[s] = 0;
    int a, b, c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int u;
    q.push((priority){0,s});
    while (!q.empty())
    {
        priority temp = q.top();
        q.pop();
        u = temp.id;
        if (!vis[u])
        {
            vis[u] = 1;
            for (int i = head[u]; i; i = edges[i].nxt)
            {
                int v = edges[i].to;
                if (ans[v] > ans[u] + edges[i].w)
                {
                    ans[v] = ans[u] + edges[i].w;
                    if (!vis[v]) q.push((priority){ans[v],v});
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}