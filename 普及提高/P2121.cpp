#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int n, m, k, fa[maxn], ans, cnt;
struct Edge
{
    int u, v, w;
};
Edge edges[maxm];
bool cmp(Edge x, Edge y)
{
    return x.w > y.w;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
    {
        fa[fy] = fx;
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges + 1, edges + m + 1, cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        if (merge(edges[i].u, edges[i].v)) cnt++, ans+=edges[i].w;
        if (cnt == k) break;
    }
    cout << ans << endl;
    return 0;
}