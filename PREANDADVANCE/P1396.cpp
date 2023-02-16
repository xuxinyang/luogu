#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
int n, m, s, t, fa[maxn];
struct Edge
{
    int x, y, cost;
};
Edge edges[maxn];
bool cmp(Edge x, Edge y)
{
    return x.cost < y.cost;
}
int find(int x)
{
    return fa[x] == 0 ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fy] = fx;
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        cin >> edges[i].x >> edges[i].y >> edges[i].cost;
    }
    sort(edges + 1, edges + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        merge(edges[i].x, edges[i].y);
        if (find(s) == find(t))
        {
            cout << edges[i].cost << endl;
            return 0;
        }
    }
    return 0;
}