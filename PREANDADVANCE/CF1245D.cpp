#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e3+5;
struct Edge
{
    int u, v;
    ll w;
};
struct Coord
{
    int x, y;
};
struct Line
{
    int x, y;
};
Line lines[maxn];
Coord coords[maxn];
Edge edges[maxn*maxn];
int n, c[maxn], k[maxn], fa[maxn], tot, cnt;
int power[maxn], p, q;
ll ans;
int manhattan(Coord A, Coord B)
{
    return abs(A.x - B.x) + abs(A.y - B.y);
}
void add(int u, int v, ll w)
{
    edges[++tot] = Edge{u, v, w};
}
int find(int x)
{
    return x == fa[x] ? x : find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fy] = fx;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n+1; i++) fa[i] = i;
    for (int i = 1; i <= n; i++)
        cin >> coords[i].x >> coords[i].y;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 1; i <= n; i++) add(i, n+1, c[i]);
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            add(i, j, 1ll * manhattan(coords[i], coords[j]) * (k[i] + k[j]));
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
            if (v == n+1) power[++p] = u;
            else lines[++q] = Line{u, v};
            merge(u, v);
            cnt++;
            ans += w;
            if (cnt == n) break;
        }
    }
    cout << ans << endl;
    cout << p << endl;
    sort(power + 1, power + p + 1);
    for (int i = 1; i <= p; i++) cout << power[i] << " ";
    cout << endl;
    cout << q << endl;
    for (int i = 1; i <= q; i++)
    {
        cout << lines[i].x << " " << lines[i].y << endl;
    }
    return 0;
}