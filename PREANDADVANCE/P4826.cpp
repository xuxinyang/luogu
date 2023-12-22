#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e3+5;
ll n, a[maxn], fa[maxn], tot, ans;
struct Edge
{
    ll u, v, w;
};
Edge edges[maxn*maxn];
int find(ll x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(ll x, ll y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fy] = fx;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        fa[i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            edges[++tot] = Edge{i, j, a[i]^a[j]};
        }
    }
    sort(edges + 1, edges + tot + 1, [](Edge x, Edge y){
        return x.w > y.w;
    });
    // for (int i = 1; i <= tot; i++) cout << edges[i].w << " ";
    int cnt = 0;
    for (int i = 1; i <= tot; i++)
    {
        ll u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v))
        {
            merge(u, v);
            cnt++;
            ans += w;
            if (cnt == n-1) break;
        }
    }
    cout << ans;
    return 0;
}