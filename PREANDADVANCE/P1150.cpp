#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 305;
int n, w[maxn], p[maxn][maxn], fa[maxn], tot, k;
ll ans;
struct Edge
{
    int u, v, w;
};
Edge edges[maxn * maxn];
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
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) fa[fy] = fx;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n + 1; i++) fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        add(i, n+1, w[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            add(i, j, p[i][j]);
        }
    }
    sort(edges + 1, edges + tot + 1, [](Edge x, Edge y){
        return x.w < y.w;
    });
    for (int i = 1; i <= tot; i++)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v))
        {
            k++;
            merge(u, v);
            ans += w;
            if (k == n) break;
        }
    }
    cout << ans;
    return 0;
}