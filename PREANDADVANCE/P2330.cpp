#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2+5;
const int maxm = 8e3+5;
int n, m, tot, fa[maxn], ans, sum;
struct Edge
{
    int u, v, w;
};
Edge edges[maxm<<1];
int find(int x)
{
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    fa[fy] = fx;
}
void kruskal()
{
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= tot; i++)
    {
        int u = edges[i].u, v = edges[i].v;
        if (find(fa[u]) != find(fa[v]))
        {
            sum++;
            merge(u, v);
        }
        if (sum + 1 == n)
        {
            ans = edges[i].w;
            break;
        }
    }
}
int main()
{
    int u, v, w;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        edges[++tot] = Edge{u, v, w};
        edges[++tot] = Edge{v, u, w};
    }
    sort(edges + 1, edges + tot + 1, [](const Edge x, const Edge y){
        return x.w < y.w;
    });
    kruskal();
    cout << sum << " " << ans;
    return 0;
}