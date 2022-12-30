#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
char c[maxn], x;
int fa[maxn], n, m, ans[maxn], cnt;
void init()
{
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) fa[fy] = fx;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    init();
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        if (c[u] == c[v]) merge(u, v);
    }
    while (m--)
    {
        cin >> u >> v >> x;
        if (find(u) == find(v) && c[u] != x) ans[++cnt] = 0;
        else ans[++cnt] = 1;
    }
    for (int i = 1; i <= cnt; i++) cout << ans[i];
    return 0;
}