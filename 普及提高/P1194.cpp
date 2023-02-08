#include <bits/stdc++.h>
using namespace std;
const int maxm = 250000;
struct Edge
{
    int u, v, w;
};
Edge edges[maxm];
int a, b, tot, ans, fa[505], val, cnt;
bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] == find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fy] = fx;
}
void kruskal()
{
    for (int i = 1; i <= tot; i++)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            merge(edges[i].u, edges[i].v);
            cnt++;
            ans += edges[i].w;
        }
        if (cnt == b) break;
    }
}
int main()
{
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> val;
            if (i < j && val != 0)
                edges[++tot].w = val, edges[tot].u = i, edges[tot].v = j;
        }
    }
    for (int i = 1; i <= b; i++)
    {
        edges[++tot].w = a, edges[tot].u = 0, edges[tot].v = i;
    }
    for (int i = 1; i <= b; i++) fa[i] = i;
    sort(edges + 1, edges + tot + 1, cmp);
    kruskal();
    cout << ans << endl;
    return 0;
}