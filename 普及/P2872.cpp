#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxm = 1e6+5;
struct Node
{
    int x, y;
};
struct Edge
{
    int u, v;
    double w;
};
int fa[maxn], n, m, ans, tot;
Node nodes[maxn];
Edge edges[maxm];
double dist(Node a, Node b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}
void init()
{
    for (int i = 1; i <= n; i++) fa[i] = i;
}
bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}
int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return 0;
    fa[fy] = fx;
    return 1;
}
double kruskal(int n)
{
    double sum = 0;
    sort(edges + 1, edges + tot + 1, cmp);
    for (int i = 1; i <= tot; i++)
    {
        if (merge(edges[i].u, edges[i].v)) n--, sum += edges[i].w;
        if (n == 1) return sum;
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].x >> nodes[i].y;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double w = dist(nodes[i], nodes[j]);
            edges[++tot] = {i, j, w};
        }
    }
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edges[++tot] = {u, v, 0.0};
    }
    cout << fixed << setprecision(2) << kruskal(n) << endl;
    return 0;
}