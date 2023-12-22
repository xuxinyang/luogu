#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxm = 2e4+5;
int n, m, fa[maxn], ans;
struct Edge
{
    int u, v, w;
};
Edge edges[maxm];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v)
{
    int fx = find(u), fy = find(v);
    if (fx != fy) fa[fy] = fx;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    sort(edges + 1, edges + m + 1, [](Edge A, Edge B){
        return A.w > B.w;
    });
    int k = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v))
        {
            merge(u, v);
            k++;
            ans += w;
            if (k == n - 1) break;
        }
        if (i == m)
        {
            puts("-1"); 
            return 0;
        }
    }
    cout << ans;
    return 0;
}