#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7+5;
ll n, tot, ans;
ll siz[maxn], head[maxn];
struct Edge
{
    ll to, next, w;
};
Edge edges[maxn << 1];
void add(ll u, ll v, ll w)
{
    edges[++tot] = (Edge){v, head[u], w};
    head[u] = tot;
}
void dfs(int x, int fa)
{
    siz[x] = 1;
    for (int i = head[x]; i; i = edges[i].next)
    {
        int to = edges[i].to;
        if (fa == to) continue;
        dfs(to, x);
        siz[x] += siz[to];
        ans += edges[i].w * abs(2 * siz[to] - n);
    }
}
int main()
{
    cin >> n;
    ll x, y, z;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}