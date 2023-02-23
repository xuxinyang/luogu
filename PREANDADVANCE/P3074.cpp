#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 5e4+5;
int n, m, ans[maxn], tot, cost[maxn], in[maxn], head[maxn];
struct Edge
{
    int to, next;
};
Edge edges[maxm];
void add(int u, int v)
{
    edges[++tot] = (Edge){v, head[u]};
    head[u] = tot;
}
queue<int> q;
void topo_sort()
{
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) ans[i] = cost[i], q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            ans[v] = max(ans[v], ans[u] + cost[v]);
            if (--in[v] == 0) q.push(v);
        }
    }
}
int main()
{
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
        in[v]++;
    }
    topo_sort();
    cout << *max_element(ans + 1, ans + n + 1);   
    return 0;
}