#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
int n, k, a[maxn], fa[maxn], tot;
ll ans;
struct Edge
{
    int u, v, w;
};
Edge edges[maxn];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{u, v, w};
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
    int x;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= k; i++)
    {
        cin >> x;
        a[x] = 1;
    }
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        ans += w;
    }
    sort(edges + 1, edges + tot + 1, [](Edge x, Edge y){
        return x.w > y.w;
    });
    for (int i = 1; i <= tot; i++)
    {
        u = edges[i].u, v = edges[i].v, w = edges[i].w;
        int fu = find(u), fv = find(v);
        if (a[fu] && a[fv]) continue;
        merge(fu, fv);  // 合并
        ans -= w;
        if (a[fu]) a[fv] = 1;   // 叛变
        else if (a[fv]) a[fu] = 1;
    }
    cout << ans;
    return 0;
}