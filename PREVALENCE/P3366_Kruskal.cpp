// kruskal 算法
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+5;
struct Edge {
    int u, v, w;
} e[N];
int fa[N], n, m, ans, cnt;
bool cmp(Edge A, Edge B) 
{
    return A.w < B.w;
}
int find(int x)
{
    if (x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}
void kruskal()
{
    sort(e+1, e+m+1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int u = find(e[i].u), v = find(e[i].v);
        if (u == v) continue;
        ans += e[i].w;
        fa[v] = u;
        cnt++;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    kruskal();
    if (cnt == n-1) cout << ans;
    else puts("orz");
    return 0;
}