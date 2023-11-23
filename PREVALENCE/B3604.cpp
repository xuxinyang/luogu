#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const int maxm = 3e5 + 5;
int n, m, head[maxn], fa[maxn], tot;
ll ans;
struct Edge
{
    int u, v, w;
};
vector<Edge> edges;
int find(int x)
{
    if (x == fa[x])
        return x;
    else
        return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    fa[fy] = fx;
}
bool operator<(Edge x, Edge y)
{
    return x.w < y.w;
}
int main()
{
    int u, v, w;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back(Edge{u, v, w});
    }
    sort(edges.begin(), edges.end());
    int k = edges.size();
    for (int i = 0; i < k; i++)
    {
        u = edges[i].u, v = edges[i].v;
        if (find(u) != find(v))
            merge(u, v), ans += edges[i].w;
    }
    cout << ans;
    return 0;
}