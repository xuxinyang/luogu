#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
const int maxm = 2e5+5;
struct Edge
{
    int u, v, w;
};
int fa[maxn], n, m, ans;
Edge edges[maxm];
void init()
{
    for (int i = 1; i <= n; i++) fa[i] = i;
}
bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}

int merge(int x, int y)
{
    int fx = fa[x];
    int fy = fa[y];
    if (fx == fy) return 0;
    for (int i = 1; i <= n; i++)
        if (fa[i] == fy) fa[i] = fx;
    return 1;
}
int kruskal(int n)
{
    int sum = 0;
    sort(edges + 1, edges + m + 1, cmp);
    for (int i = 1; i <= m; i++)
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
    for (int i = 1; i <= m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    bool flag = 0;
    ans = kruskal(n);
    int k = fa[1];
    for (int i = 2; i <= n; i++)
    {
        if (fa[i] != k) flag = 1;
    }
    if (flag) cout << "orz";
    else cout << ans;
    return 0;
}