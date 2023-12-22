#include <bits/stdc++.h>
using namespace std;
const int maxm = 505;
const int maxn = 1e3+5;
int m, n, p[maxm], t, c, fa[maxn], d, ans;
double maxx;
struct Coord
{
    int x, y;
};
Coord coords[maxn];
struct Edge
{
    int u, v;
    double w;
};
Edge edges[maxn*maxn];
double dist(Coord A, Coord B)
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fy] = fx;
}
int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> p[i];
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        coords[++t] = {x, y};
        fa[i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            edges[++c] = Edge{i, j, dist(coords[i], coords[j])};
        }
    }
    sort(edges + 1, edges + c + 1, [](Edge A, Edge B){
        return A.w < B.w;
    });
    int k = 0;
    for (int i = 1; i <= c; i++)
    {
        int u = edges[i].u, v = edges[i].v;
        double w = edges[i].w;
        if (find(u) != find(v))
        {
            merge(u, v);
            k++;
            maxx = max(maxx, w);
            if (k == n - 1) break;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (p[i] >= maxx) ans++;
    }
    cout << ans;
    return 0;
}