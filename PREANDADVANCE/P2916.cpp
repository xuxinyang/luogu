#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 1e5+5;
const int inf = INT_MAX;
int n, p, a[maxn], ans, fa[maxn], minx;
struct Edge
{
    int u, v, w;
    bool operator < (const Edge A) const
    {
        return w < A.w;
    }
};
vector<Edge> ve;
int find(int x)
{
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    fa[fy] = fx;
}
void kruskal()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i < ve.size();i++)
    {
        int u = ve[i].u, v = ve[i].v;
        if (find(fa[u]) != find(fa[v]))
        {
            merge(u, v);
            ans += ve[i].w;
            cnt++;
        }
        if (cnt == n-1) break;
    }
}

int main()
{
    int u, v, w;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    minx = *min_element(a + 1, a + n + 1);
    for (int i = 1; i <= p; i++)
    {
        cin >> u >> v >> w;
        ve.push_back(Edge{u, v, w * 2 + a[u] + a[v]});
        ve.push_back(Edge{v, u, w * 2 + a[u] + a[v]});
    }
    sort(ve.begin(), ve.end());
    kruskal();
    cout << ans + minx;
    return 0;
}