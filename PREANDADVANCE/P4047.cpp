#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxm = 1e6+5;
int k, n, tot, fa[maxn], cnt, flag;
double ans;
struct Edge
{
    int u, v;
    double w;
};
struct Coord
{
    int x, y;
};
Coord coords[maxn];
Edge edges[maxm];
bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fx] = fy;
}
void add(int u, int v, double w)
{
    edges[++tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
}
double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
void kruskal()
{
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= tot; i++)
    {
        if (cnt == n-k) flag = true;
        if (find(edges[i].u) != find(edges[i].v))
        {
            merge(edges[i].u, edges[i].v);
            cnt++;
            if (flag)
            {
                cout << fixed << setprecision(2) << edges[i].w << endl;
                return;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> coords[i].x >> coords[i].y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            double w = dist(coords[i].x, coords[i].y, coords[j].x, coords[j].y);
            add(i, j, w);
        }
    }
    sort(edges + 1, edges + tot + 1, cmp);
    kruskal();
    return 0;
}